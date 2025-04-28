#!/bin/bash

cd cmake-build-debug/build/Debug || exit 1
make "$@"