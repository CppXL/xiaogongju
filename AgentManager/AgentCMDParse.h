#ifndef _AGENTCMDPARSE_H_
#define _AGENTCMDPARSE_H_

#include "../generic.h"
#include "AgentProNet.h"
#include "AgentProtocol.h"
/////  第一字段 指令类型
#define CMDTYPE_NEWCONN     1 // 节点连接协议
#define CMDTYPE_TRANSMIT    2 // 节点间交互协议
#define CMDTYPE_TUNNELCTRL  3 // 节点间隧道
#define CMDTYPE_MANGER_U    4 // 设置上下游节点状态

/////  第二字段 指令编号
#define CMDID_UNKNOWN          0 // 未知默认值
#define CMDID_JOB_RPLY         1 // 工作回馈 
//tunnel
#define CMDID_NEWTUNNEL_ASK    2 // 新隧道请求(直连)
#define CMDID_NEWTUNNEL_RC_ASK 3 // 新隧道请求(反向)
#define CMDID_NEWTUNNEL_RC_RPL 4 // 新隧道响应(反向)
// id ask
#define CMDID_NEWID_ASK        5 // 向上级请求新ID
#define CMDID_NEWID_RPL        6 // 新ID分配响应
#define CMDID_ID_RESET         7 // ID重置
// agent conn sync
#define CMDID_CHILDSYNC_UPPER  8 // 向上级更新节点信息
#define CMDID_NEWNODE_HERE     9 // 新节点连接


/////  内置ID控制
#define AGENTID_ADMIN             0 
    // 管理员节点的默认ID
#define AGENTID_UNKNOWN      0xf7f7f7f
    // 信息和节点ID无关时，使用-1
#define AGENTID_ALL_AGENT    0xf7f7f7e 
    // 信息将发给所有节点 
#define AGENTID_UPPER_AGENT  0xf7f7f7d
    // 信息将发给所有上游节点,并递归上传
#define AGENTID_DOWN_AGENT   0xf7f7f7c
    // 信息将广播给所有下游节点,并递归下传


#define CMDPARSE_AND_DO_ERROR     -1
#define CMDPARSE_AND_DO_OK         1
int CMDParse_And_Do(pAgent_proto proto,pPCConn conn);

#define CMDPARSE_SENDPROTO_UPPER_ERROR   -1
#define CMDPARSE_SENDPROTO_UPPER_OK       1
int CMDParse_SendProto_Upper(pAgent_proto proto);

#endif
