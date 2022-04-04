# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from autoware_msgs/ImageLaneObjects.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class ImageLaneObjects(genpy.Message):
  _md5sum = "851175a106269dc1f4c64f0c36bafb05"
  _type = "autoware_msgs/ImageLaneObjects"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """Header header
int32 lane_l_x1 # Left Lane
int32 lane_l_y1
int32 lane_l_x2
int32 lane_l_y2
int32 lane_r_x1 # Right Lane
int32 lane_r_y1
int32 lane_r_x2
int32 lane_r_y2

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id
"""
  __slots__ = ['header','lane_l_x1','lane_l_y1','lane_l_x2','lane_l_y2','lane_r_x1','lane_r_y1','lane_r_x2','lane_r_y2']
  _slot_types = ['std_msgs/Header','int32','int32','int32','int32','int32','int32','int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,lane_l_x1,lane_l_y1,lane_l_x2,lane_l_y2,lane_r_x1,lane_r_y1,lane_r_x2,lane_r_y2

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ImageLaneObjects, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.lane_l_x1 is None:
        self.lane_l_x1 = 0
      if self.lane_l_y1 is None:
        self.lane_l_y1 = 0
      if self.lane_l_x2 is None:
        self.lane_l_x2 = 0
      if self.lane_l_y2 is None:
        self.lane_l_y2 = 0
      if self.lane_r_x1 is None:
        self.lane_r_x1 = 0
      if self.lane_r_y1 is None:
        self.lane_r_y1 = 0
      if self.lane_r_x2 is None:
        self.lane_r_x2 = 0
      if self.lane_r_y2 is None:
        self.lane_r_y2 = 0
    else:
      self.header = std_msgs.msg.Header()
      self.lane_l_x1 = 0
      self.lane_l_y1 = 0
      self.lane_l_x2 = 0
      self.lane_l_y2 = 0
      self.lane_r_x1 = 0
      self.lane_r_y1 = 0
      self.lane_r_x2 = 0
      self.lane_r_y2 = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_8i().pack(_x.lane_l_x1, _x.lane_l_y1, _x.lane_l_x2, _x.lane_l_y2, _x.lane_r_x1, _x.lane_r_y1, _x.lane_r_x2, _x.lane_r_y2))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 32
      (_x.lane_l_x1, _x.lane_l_y1, _x.lane_l_x2, _x.lane_l_y2, _x.lane_r_x1, _x.lane_r_y1, _x.lane_r_x2, _x.lane_r_y2,) = _get_struct_8i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_8i().pack(_x.lane_l_x1, _x.lane_l_y1, _x.lane_l_x2, _x.lane_l_y2, _x.lane_r_x1, _x.lane_r_y1, _x.lane_r_x2, _x.lane_r_y2))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 32
      (_x.lane_l_x1, _x.lane_l_y1, _x.lane_l_x2, _x.lane_l_y2, _x.lane_r_x1, _x.lane_r_y1, _x.lane_r_x2, _x.lane_r_y2,) = _get_struct_8i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_8i = None
def _get_struct_8i():
    global _struct_8i
    if _struct_8i is None:
        _struct_8i = struct.Struct("<8i")
    return _struct_8i
