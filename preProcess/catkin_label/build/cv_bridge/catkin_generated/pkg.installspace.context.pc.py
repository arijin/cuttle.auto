# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/usr/local/include;/usr/local/include/opencv".split(';') if "${prefix}/include;/usr/local/include;/usr/local/include/opencv" != "" else []
PROJECT_CATKIN_DEPENDS = "rosconsole;sensor_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lcv_bridge;/usr/local/lib/libopencv_core.so.3.4.3;/usr/local/lib/libopencv_imgproc.so.3.4.3;/usr/local/lib/libopencv_imgcodecs.so.3.4.3".split(';') if "-lcv_bridge;/usr/local/lib/libopencv_core.so.3.4.3;/usr/local/lib/libopencv_imgproc.so.3.4.3;/usr/local/lib/libopencv_imgcodecs.so.3.4.3" != "" else []
PROJECT_NAME = "cv_bridge"
PROJECT_SPACE_DIR = "/home/arijin/cuttle.auto/preProcess/catkin_label/install"
PROJECT_VERSION = "1.13.0"
