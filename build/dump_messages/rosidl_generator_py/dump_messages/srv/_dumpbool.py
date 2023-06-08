# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dump_messages:srv/Dumpbool.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Dumpbool_Request(type):
    """Metaclass of message 'Dumpbool_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('dump_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dump_messages.srv.Dumpbool_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__dumpbool__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__dumpbool__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__dumpbool__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__dumpbool__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__dumpbool__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Dumpbool_Request(metaclass=Metaclass_Dumpbool_Request):
    """Message class 'Dumpbool_Request'."""

    __slots__ = [
        '_request',
    ]

    _fields_and_field_types = {
        'request': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.request = kwargs.get('request', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.request != other.request:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'request' field must be of type 'bool'"
        self._request = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_Dumpbool_Response(type):
    """Metaclass of message 'Dumpbool_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('dump_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dump_messages.srv.Dumpbool_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__dumpbool__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__dumpbool__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__dumpbool__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__dumpbool__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__dumpbool__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Dumpbool_Response(metaclass=Metaclass_Dumpbool_Response):
    """Message class 'Dumpbool_Response'."""

    __slots__ = [
        '_bit',
    ]

    _fields_and_field_types = {
        'bit': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.bit = kwargs.get('bit', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.bit != other.bit:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def bit(self):
        """Message field 'bit'."""
        return self._bit

    @bit.setter
    def bit(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'bit' field must be of type 'bool'"
        self._bit = value


class Metaclass_Dumpbool(type):
    """Metaclass of service 'Dumpbool'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('dump_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dump_messages.srv.Dumpbool')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__dumpbool

            from dump_messages.srv import _dumpbool
            if _dumpbool.Metaclass_Dumpbool_Request._TYPE_SUPPORT is None:
                _dumpbool.Metaclass_Dumpbool_Request.__import_type_support__()
            if _dumpbool.Metaclass_Dumpbool_Response._TYPE_SUPPORT is None:
                _dumpbool.Metaclass_Dumpbool_Response.__import_type_support__()


class Dumpbool(metaclass=Metaclass_Dumpbool):
    from dump_messages.srv._dumpbool import Dumpbool_Request as Request
    from dump_messages.srv._dumpbool import Dumpbool_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
