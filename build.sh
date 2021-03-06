#!/bin/bash

NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'

CMAKE_BUILD_DIR="../out"
PROJECT_NAME="Isolation"
BUILD_TYPE="Debug"
POSTFIX="-d"

configure() {
    echo -e "configuring cmake..."
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=$BUILD_TYPE -S . -B $CMAKE_BUILD_DIR && cp $CMAKE_BUILD_DIR/compile_commands.json .
}

build() {
    echo -e "building..."
    cmake --build $CMAKE_BUILD_DIR --config $BUILD_TYPE || (configure && cmake --build $CMAKE_BUILD_DIR --config $BUILD_TYPE)
}

build_and_run() {
    build && run
}

run() {
    echo -e "running..."
    $CMAKE_BUILD_DIR/bin/$PROJECT_NAME$POSTFIX || (build && $CMAKE_BUILD_DIR/bin/$PROJECT_NAME)
}

clean_all() {
    echo -e "cleaning..."
    rm -rf $CMAKE_BUILD_DIR/*
    rm -rf $CMAKE_BUILD_DIR/.*
}

change_build_type() {
    echo -e "Build type -> ${GREEN}${BUILD_TYPE}${NOCOLOR}\n"
    echo -e "Choose build type:\n (${RED}d${NOCOLOR})Debug, (${RED}r${NOCOLOR})Release"
    read -n 1 -s input
    case $input in
        d)
            BUILD_TYPE="Debug"
            POSTFIX="-d"
            ;;
        r)
            BUILD_TYPE="Release"
            POSTFIX=""
            ;;
        *)
            ;;
    esac
}

while true
do
echo -e "\n \
Build type -> ${GREEN}${BUILD_TYPE}${NOCOLOR}\n \
(${RED}1${NOCOLOR}) configure cmake, \
(${RED}2${NOCOLOR}) build, \
(${RED}3${NOCOLOR}) build & run, \
(${RED}4${NOCOLOR}) run, \
(${RED}5${NOCOLOR}) clean all, \
(${GREEN}q${NOCOLOR}) exit \
"
read -n 1 -s input
case $input in
    1)
        configure
        ;;
    2)
        build
        ;;
    3)
        build_and_run
        ;;
    4)
        run
        ;;
    5)
        clean_all
        ;;
    *)
        exit
        ;;
esac
done
