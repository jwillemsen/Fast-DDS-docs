/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * fastcdr_LICENSE file included in this fastcdr distribution.
 *
 *************************************************************************
 * 
 * @file FlowControlExamplePubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _FLOWCONTROLEXAMPLE_PUBSUBTYPES_H_
#define _FLOWCONTROLEXAMPLE_PUBSUBTYPES_H_

#include <fastrtps/TopicDataType.h>

using namespace eprosima::fastrtps;

#include "FlowControlExample.h"

/*!
 * @brief This class represents the TopicDataType of the type FlowControlExample defined by the user in the IDL file.
 * @ingroup FLOWCONTROLEXAMPLE
 */
class FlowControlExamplePubSubType : public TopicDataType {
public:
	FlowControlExamplePubSubType();
	virtual ~FlowControlExamplePubSubType();
	bool serialize(void *data, SerializedPayload_t *payload);
	bool deserialize(SerializedPayload_t *payload, void *data);
	bool getKey(void *data, InstanceHandle_t *ihandle);
	void* createData();
	void deleteData(void * data);
	MD5 m_md5;
	unsigned char* m_keyBuffer;
};

#endif // _FlowControlExample_PUBSUBTYPE_H_