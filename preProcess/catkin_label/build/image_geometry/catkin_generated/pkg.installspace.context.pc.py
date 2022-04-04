# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/usr/local/include;/usr/local/include/opencv".split(';') if "${prefix}/include;/usr/local/include;/usr/local/include/opencv" != "" else []
PROJECT_CATKIN_DEPENDS = "sensor_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-limage_geometry;/usr/local/lib/libopencv_calib3d.so.3.4.3;/usr/local/lib/libopencv_core.so.3.4.3;/usr/local/lib/libopencv_dnn.so.3.4.3;/usr/local/lib/libopencv_features2d.so.3.4.3;/usr/local/lib/libopencv_flann.so.3.4.3;/usr/local/lib/libopencv_highgui.so.3.4.3;/usr/local/lib/libopencv_imgcodecs.so.3.4.3;/usr/local/lib/libopencv_imgproc.so.3.4.3;/usr/local/lib/libopencv_ml.so.3.4.3;/usr/local/lib/libopencv_objdetect.so.3.4.3;/usr/local/lib/libopencv_photo.so.3.4.3;/usr/local/lib/libopencv_shape.so.3.4.3;/usr/local/lib/libopencv_stitching.so.3.4.3;/usr/local/lib/libopencv_superres.so.3.4.3;/usr/local/lib/libopencv_video.so.3.4.3;/usr/local/lib/libopencv_videoio.so.3.4.3;/usr/local/lib/libopencv_videostab.so.3.4.3;/usr/local/lib/libopencv_viz.so.3.4.3;/usr/local/lib/libopencv_aruco.so.3.4.3;/usr/local/lib/libopencv_bgsegm.so.3.4.3;/usr/local/lib/libopencv_bioinspired.so.3.4.3;/usr/local/lib/libopencv_ccalib.so.3.4.3;/usr/local/lib/libopencv_cvv.so.3.4.3;/usr/local/lib/libopencv_datasets.so.3.4.3;/usr/local/lib/libopencv_dnn_objdetect.so.3.4.3;/usr/local/lib/libopencv_dpm.so.3.4.3;/usr/local/lib/libopencv_face.so.3.4.3;/usr/local/lib/libopencv_freetype.so.3.4.3;/usr/local/lib/libopencv_fuzzy.so.3.4.3;/usr/local/lib/libopencv_hfs.so.3.4.3;/usr/local/lib/libopencv_img_hash.so.3.4.3;/usr/local/lib/libopencv_line_descriptor.so.3.4.3;/usr/local/lib/libopencv_optflow.so.3.4.3;/usr/local/lib/libopencv_phase_unwrapping.so.3.4.3;/usr/local/lib/libopencv_plot.so.3.4.3;/usr/local/lib/libopencv_reg.so.3.4.3;/usr/local/lib/libopencv_rgbd.so.3.4.3;/usr/local/lib/libopencv_saliency.so.3.4.3;/usr/local/lib/libopencv_sfm.so.3.4.3;/usr/local/lib/libopencv_stereo.so.3.4.3;/usr/local/lib/libopencv_structured_light.so.3.4.3;/usr/local/lib/libopencv_surface_matching.so.3.4.3;/usr/local/lib/libopencv_text.so.3.4.3;/usr/local/lib/libopencv_tracking.so.3.4.3;/usr/local/lib/libopencv_xfeatures2d.so.3.4.3;/usr/local/lib/libopencv_ximgproc.so.3.4.3;/usr/local/lib/libopencv_xobjdetect.so.3.4.3;/usr/local/lib/libopencv_xphoto.so.3.4.3".split(';') if "-limage_geometry;/usr/local/lib/libopencv_calib3d.so.3.4.3;/usr/local/lib/libopencv_core.so.3.4.3;/usr/local/lib/libopencv_dnn.so.3.4.3;/usr/local/lib/libopencv_features2d.so.3.4.3;/usr/local/lib/libopencv_flann.so.3.4.3;/usr/local/lib/libopencv_highgui.so.3.4.3;/usr/local/lib/libopencv_imgcodecs.so.3.4.3;/usr/local/lib/libopencv_imgproc.so.3.4.3;/usr/local/lib/libopencv_ml.so.3.4.3;/usr/local/lib/libopencv_objdetect.so.3.4.3;/usr/local/lib/libopencv_photo.so.3.4.3;/usr/local/lib/libopencv_shape.so.3.4.3;/usr/local/lib/libopencv_stitching.so.3.4.3;/usr/local/lib/libopencv_superres.so.3.4.3;/usr/local/lib/libopencv_video.so.3.4.3;/usr/local/lib/libopencv_videoio.so.3.4.3;/usr/local/lib/libopencv_videostab.so.3.4.3;/usr/local/lib/libopencv_viz.so.3.4.3;/usr/local/lib/libopencv_aruco.so.3.4.3;/usr/local/lib/libopencv_bgsegm.so.3.4.3;/usr/local/lib/libopencv_bioinspired.so.3.4.3;/usr/local/lib/libopencv_ccalib.so.3.4.3;/usr/local/lib/libopencv_cvv.so.3.4.3;/usr/local/lib/libopencv_datasets.so.3.4.3;/usr/local/lib/libopencv_dnn_objdetect.so.3.4.3;/usr/local/lib/libopencv_dpm.so.3.4.3;/usr/local/lib/libopencv_face.so.3.4.3;/usr/local/lib/libopencv_freetype.so.3.4.3;/usr/local/lib/libopencv_fuzzy.so.3.4.3;/usr/local/lib/libopencv_hfs.so.3.4.3;/usr/local/lib/libopencv_img_hash.so.3.4.3;/usr/local/lib/libopencv_line_descriptor.so.3.4.3;/usr/local/lib/libopencv_optflow.so.3.4.3;/usr/local/lib/libopencv_phase_unwrapping.so.3.4.3;/usr/local/lib/libopencv_plot.so.3.4.3;/usr/local/lib/libopencv_reg.so.3.4.3;/usr/local/lib/libopencv_rgbd.so.3.4.3;/usr/local/lib/libopencv_saliency.so.3.4.3;/usr/local/lib/libopencv_sfm.so.3.4.3;/usr/local/lib/libopencv_stereo.so.3.4.3;/usr/local/lib/libopencv_structured_light.so.3.4.3;/usr/local/lib/libopencv_surface_matching.so.3.4.3;/usr/local/lib/libopencv_text.so.3.4.3;/usr/local/lib/libopencv_tracking.so.3.4.3;/usr/local/lib/libopencv_xfeatures2d.so.3.4.3;/usr/local/lib/libopencv_ximgproc.so.3.4.3;/usr/local/lib/libopencv_xobjdetect.so.3.4.3;/usr/local/lib/libopencv_xphoto.so.3.4.3" != "" else []
PROJECT_NAME = "image_geometry"
PROJECT_SPACE_DIR = "/home/arijin/cuttle.auto/preProcess/catkin_label/install"
PROJECT_VERSION = "1.13.0"
