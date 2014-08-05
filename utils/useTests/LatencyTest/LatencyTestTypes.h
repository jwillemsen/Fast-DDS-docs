/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima RTPS is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file LatencyTestTypes.h
 *
 */

#ifndef LATENCYTESTTYPES_H_
#define LATENCYTESTTYPES_H_

#include "eprosimartps/rtps_all.h"

#define NSAMPLES 10000


class LatencyType{
public:
	uint32_t seqnum;
	std::vector<uint8_t> data;
	LatencyType():
		seqnum(0)
	{
		seqnum = 0;
	}
	LatencyType(uint16_t number):
		seqnum(0),
		data(number,0)
	{

	}
	~LatencyType()
	{

	}
};


inline bool operator==(LatencyType& lt1, LatencyType& lt2)
{
	if(lt1.seqnum!=lt2.seqnum)
		return false;
	if(lt1.data.size()!=lt2.data.size())
		return false;
	for(size_t i = 0;i<lt1.data.size();++i)
	{
		if(lt1.data.at(i) != lt2.data.at(i))
			return false;
	}
	return true;
}

class LatencyDataType: public DDSTopicDataType
{
public:
	LatencyDataType()
{
		m_topicDataTypeName = "LatencyType";
		m_typeSize = 15000;
		m_isGetKeyDefined = false;
};
	~LatencyDataType(){};
	bool serialize(void*data,SerializedPayload_t* payload);
	bool deserialize(SerializedPayload_t* payload,void * data);
};

enum TESTCOMMAND:uint32_t{
	DEFAULT,
	READY,
	BEGIN,
	STOP,
	STOP_ERROR
};

typedef struct TestCommandType
{
	TESTCOMMAND m_command;
	TestCommandType(){
		m_command = DEFAULT;
	}
	TestCommandType(TESTCOMMAND com):m_command(com){}
}TestCommandType;

class TestCommandDataType:public DDSTopicDataType
{
public:
	TestCommandDataType()
{
		m_topicDataTypeName = "TestCommandType";
		m_typeSize = 4;
		m_isGetKeyDefined = false;
};
	~TestCommandDataType(){};
	bool serialize(void*data,SerializedPayload_t* payload);
	bool deserialize(SerializedPayload_t* payload,void * data);
};


#endif /* LATENCYTESTTYPES_H_ */