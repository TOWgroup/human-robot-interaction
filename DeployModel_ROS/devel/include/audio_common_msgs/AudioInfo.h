// Generated by gencpp from file audio_common_msgs/AudioInfo.msg
// DO NOT EDIT!


#ifndef AUDIO_COMMON_MSGS_MESSAGE_AUDIOINFO_H
#define AUDIO_COMMON_MSGS_MESSAGE_AUDIOINFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace audio_common_msgs
{
template <class ContainerAllocator>
struct AudioInfo_
{
  typedef AudioInfo_<ContainerAllocator> Type;

  AudioInfo_()
    : channels(0)
    , sample_rate(0)
    , sample_format()
    , bitrate(0)
    , coding_format()  {
    }
  AudioInfo_(const ContainerAllocator& _alloc)
    : channels(0)
    , sample_rate(0)
    , sample_format(_alloc)
    , bitrate(0)
    , coding_format(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _channels_type;
  _channels_type channels;

   typedef uint32_t _sample_rate_type;
  _sample_rate_type sample_rate;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _sample_format_type;
  _sample_format_type sample_format;

   typedef uint32_t _bitrate_type;
  _bitrate_type bitrate;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _coding_format_type;
  _coding_format_type coding_format;





  typedef boost::shared_ptr< ::audio_common_msgs::AudioInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::audio_common_msgs::AudioInfo_<ContainerAllocator> const> ConstPtr;

}; // struct AudioInfo_

typedef ::audio_common_msgs::AudioInfo_<std::allocator<void> > AudioInfo;

typedef boost::shared_ptr< ::audio_common_msgs::AudioInfo > AudioInfoPtr;
typedef boost::shared_ptr< ::audio_common_msgs::AudioInfo const> AudioInfoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::audio_common_msgs::AudioInfo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::audio_common_msgs::AudioInfo_<ContainerAllocator1> & lhs, const ::audio_common_msgs::AudioInfo_<ContainerAllocator2> & rhs)
{
  return lhs.channels == rhs.channels &&
    lhs.sample_rate == rhs.sample_rate &&
    lhs.sample_format == rhs.sample_format &&
    lhs.bitrate == rhs.bitrate &&
    lhs.coding_format == rhs.coding_format;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::audio_common_msgs::AudioInfo_<ContainerAllocator1> & lhs, const ::audio_common_msgs::AudioInfo_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace audio_common_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::audio_common_msgs::AudioInfo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::audio_common_msgs::AudioInfo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::audio_common_msgs::AudioInfo_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9413d9b7029680d3b1db6ed0ae535f88";
  }

  static const char* value(const ::audio_common_msgs::AudioInfo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9413d9b7029680d3ULL;
  static const uint64_t static_value2 = 0xb1db6ed0ae535f88ULL;
};

template<class ContainerAllocator>
struct DataType< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "audio_common_msgs/AudioInfo";
  }

  static const char* value(const ::audio_common_msgs::AudioInfo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This message contains the audio meta data\n"
"\n"
"# Number of channels\n"
"uint8 channels\n"
"# Sampling rate [Hz]\n"
"uint32 sample_rate\n"
"# Audio format (e.g. S16LE)\n"
"string sample_format\n"
"# Amount of audio data per second [bits/s]\n"
"uint32 bitrate\n"
"# Audio coding format (e.g. WAVE, MP3)\n"
"string coding_format\n"
;
  }

  static const char* value(const ::audio_common_msgs::AudioInfo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.channels);
      stream.next(m.sample_rate);
      stream.next(m.sample_format);
      stream.next(m.bitrate);
      stream.next(m.coding_format);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AudioInfo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::audio_common_msgs::AudioInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::audio_common_msgs::AudioInfo_<ContainerAllocator>& v)
  {
    s << indent << "channels: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.channels);
    s << indent << "sample_rate: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.sample_rate);
    s << indent << "sample_format: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.sample_format);
    s << indent << "bitrate: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.bitrate);
    s << indent << "coding_format: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.coding_format);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUDIO_COMMON_MSGS_MESSAGE_AUDIOINFO_H
