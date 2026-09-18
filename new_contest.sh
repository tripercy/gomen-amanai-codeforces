#!/usr/bin/env bash

# Exit on error
set -e

if [ -z "$TMUX" ]; then
    echo "Error: This script must be run inside an active tmux session."
    exit 1
fi

TEMPLATE_DIR="template"

# Check if a project name was provided
if [ -z "$1" ]; then
    echo "Usage: $0 <project-name>"
    exit 1
fi

PROJECT_NAME="$1"
TARGET_DIR="$(pwd)/$PROJECT_NAME"

# 1. Create directory and copy template
if [ ! -d "$TARGET_DIR" ]; then
    echo "Creating '$TARGET_DIR' from '$TEMPLATE_DIR'..."
    mkdir -p "$TARGET_DIR"
    if [ -d "$TEMPLATE_DIR" ]; then
        cp -r "$TEMPLATE_DIR/." "$TARGET_DIR/"
    fi
fi


# 2. Create new tmux window named after the project in TARGET_DIR
# -P -F "#{window_id}" creates the window and captures its unique ID (e.g. @2)
NEW_WIN_ID=$(tmux new-window -P -F "#{window_id}" -n "$PROJECT_NAME" -c "$TARGET_DIR" "nvim .")

# 3. Split window to create 3 total panes directly in TARGET_DIR
NVIM_SPLIT_CMD="nvim _input.txt -c 'split _expect.txt' -c 'vsplit _output.txt'"
tmux split-window -t "$NEW_WIN_ID" -h -c "$TARGET_DIR" "$NVIM_SPLIT_CMD"
tmux split-window -t "$NEW_WIN_ID.1" -v -c "$TARGET_DIR" 

# 4. Apply your exact custom layout
CUSTOM_LAYOUT="6e70,189x50,0,0{102x50,0,0[102x34,0,0,81,102x15,0,35,83],86x50,103,0,82}"
tmux select-layout -t "$NEW_WIN_ID" "$CUSTOM_LAYOUT"

# 5. Focus the top-left (primary) pane
tmux select-pane -t "$NEW_WIN_ID.1"
