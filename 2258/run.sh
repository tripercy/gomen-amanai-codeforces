#!/usr/bin/env bash

set -e
INPUT=_input.txt
OUTPUT=_output.txt
ERR=_err
COMPILER=g++

FLAGS=
POSITIONAL_ARGS=()

while [[ $# -gt 0 ]]; do
    case "$1" in
    -h | --help)
        echo "Usage: $0 [-h|-D|--debug] <problem>"
        exit 0
        ;;
    -D | --debug)
        FLAGS="-DLOCAL"
        shift # Past -V
        ;;
    -*)
        echo "Invalid option: $1" >&2
        exit 1
        ;;
    *)
        # Save non-flag positional arguments
        POSITIONAL_ARGS+=("$1")
        shift
        ;;
    esac
done

# Restore positional arguments into $1, $2, etc.
set -- "${POSITIONAL_ARGS[@]}"

if [ -z "$1" ]; then
    echo "Usage: $0 <problem> [-V]"
    exit 1
fi

PROBLEM=$1
PROBLEM="${PROBLEM%.cpp}"
SOURCE=$PROBLEM.cpp
TARGET=_$PROBLEM.out

echo "$COMPILER $SOURCE -o $TARGET $FLAGS"
$COMPILER $SOURCE -o $TARGET $FLAGS
echo "./$TARGET <$INPUT 1>$OUTPUT 2>$ERR"
./$TARGET <$INPUT 1>$OUTPUT 2>$ERR
