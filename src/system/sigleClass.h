#pragma once
#include <stdio.h>
#define SINGLETON(className) \
    friend class CGarbo##className; \
    public:\
        static className* className::instance()\
        {\
            if (_instance == NULL)\
            {\
                _instance = new className;\
            }\
            return _instance;\
        }; \
    protected: \
        className(); \
        ~className(); \
    private: \
        static className* _instance;

#define SINGLETON_GARBO(className) \
    className* className::_instance = nullptr; \
    class CGarbo##className\
    {\
    public:\
                ~CGarbo##className()\
                {\
                    if (className::_instance != nullptr)\
                    {\
                        delete className::_instance;\
                        className::_instance = nullptr;\
                    }\
                };\
    };\
    static CGarbo##className _garbo;