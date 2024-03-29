echo "echo Restoring environment" > "/home/ktsoupos/CLionProjects/obc-software-PWM/cmake-build-debug/build/Debug/generators/deactivate_conanbuildenv-debug-armv7.sh"
for v in CXX CC
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "/home/ktsoupos/CLionProjects/obc-software-PWM/cmake-build-debug/build/Debug/generators/deactivate_conanbuildenv-debug-armv7.sh"
    else
        echo unset $v >> "/home/ktsoupos/CLionProjects/obc-software-PWM/cmake-build-debug/build/Debug/generators/deactivate_conanbuildenv-debug-armv7.sh"
    fi
done


export CXX="/usr/bin/arm-none-eabi-g++"
export CC="/usr/bin/arm-none-eabi-gcc"