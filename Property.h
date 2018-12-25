#pragma once

#define PropertyDecare(type, name, init_value) type name = init_value;
#define PropertyDecareNoInit(type, name) type name;

#define PropertyGetter(type, name) type Get##name(){return name;}

#define PropertyGetterReference(type, name) const type & Get##name##ConstReference(){return name;}

#define PropertyGetterReferenceNoConstant(type, name) type & Get##name##Reference(){return name;}

#define PropertySetter(type, name) void Set##name(const type & _value){name = _value;}


#define PropertyPrivate(type, name, init_value) \
private:\
	PropertyDecare(type, name, init_value)

#define PropertyPrivateNoInit(type, name) \
private:\
	PropertyDecareNoInit(type, name)

#define PropertyReadOnly(type, name, init_value) \
	PropertyPrivate(type, name, init_value)\
public:\
	PropertyGetter(type, name)

#define PropertyReadOnlyNoInit(type, name) \
	PropertyPrivateNoInit(type, name)\
public:\
	PropertyGetter(type, name)

#define PropertyReadWrite(type, name, init_value) \
	PropertyReadOnly(type, name, init_value)\
public:\
	PropertySetter(type, name)

#define PropertyReadWriteNoInit(type, name) \
	PropertyReadOnlyNoInit(type, name)\
public:\
	PropertySetter(type, name)

#define PropertyObjectReadOnly(type, name, init_value) \
	PropertyReadOnly(type, name, init_value)\
public:\
	PropertyGetterReference(type, name)\
	PropertyGetterReferenceNoConstant(type, name)

#define PropertyObjectReadOnlyNoInit(type, name) \
	PropertyReadOnlyNoInit(type, name)\
public:\
	PropertyGetterReference(type, name)\
	PropertyGetterReferenceNoConstant(type, name)

#define PropertyObjectReadWrite(type, name, init_value) \
	PropertyObjectReadOnly(type, name, init_value)\
public:\
	PropertySetter(type, name)

#define PropertyObjectReadWriteNoInit(type, name) \
	PropertyObjectReadOnlyNoInit(type, name)\
public:\
	PropertySetter(type, name)