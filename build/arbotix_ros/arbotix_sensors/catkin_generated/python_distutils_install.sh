#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/src/arbotix_ros/arbotix_sensors"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/install/lib/python2.7/dist-packages:/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/build" \
    "/usr/bin/python2" \
    "/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/src/arbotix_ros/arbotix_sensors/setup.py" \
     \
    build --build-base "/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/build/arbotix_ros/arbotix_sensors" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/install" --install-scripts="/home/lizhangxun/GYROBOT_RVIZ_GAZEBO/install/bin"
