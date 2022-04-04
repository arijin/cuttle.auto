# robotx_label

```shell
catkin config -DPYTHON_EXECUTABLE=/usr/bin/python3 -DPYTHON_INCLUDE_DIR=/usr/include/python3.6m -DPYTHON_LIBRARY=/usr/lib/x86_64-linux-gnu/libpython3.6m.so
catkin config --install
# build
catkin build cv_bridge water_msgs
catkin build
source install/setup.bash --extend
```

测试python3下的cv_bridge功能

```python
from cv_bridge.boost.cv_bridge_boost import getCvType
```



