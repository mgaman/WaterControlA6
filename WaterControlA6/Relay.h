#include "Configuration.h"

void RelaySet(int l1,int l2);

enum tapState {TAP_UNKNOWN=0,TAP_CLOSE,TAP_OPEN};  // make these correspond to ENUM in SQL create table
extern enum tapState lasttap;

void TapChangeState(enum tapState t);
const char *TapToText();
