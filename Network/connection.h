#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <kernel/OS.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "definitions.h"
#include "types.h"

class CConnection
{
public:
	CConnection();
	~CConnection();
	
	status_t	SetRemoteAddress(char* host);
	void    	SetRemoteConnectingAddress(sockaddr_in& RemoteAddress);

	void	RtpUdpMode(MODE);
	void	RtcpUdpMode(MODE);

	void	SendRtpUdp(char *data, int packetType, int size);
	int		RecvRtpUdp(char* pchBuffer, int nMaxLen);

	void	SendRtcpUdp(char *data);

	int     RecvRtcpUdp(char* pchBuffer, int nMaxLen, sockaddr_in& lRemoteAddress);

	const char*	GetRemoteIP()					{return inet_ntoa(addressRemoteRtpUdp.sin_addr);}

private: // functions
	long GetLocalAddr();
	
private: // data
	int socketSendRtpUdp;
	int socketRecvRtpUdp;
	int socketSendRtcpUdp;
	int socketRecvRtcpUdp;
	
	sockaddr_in addressLocalRtpUdp;
	sockaddr_in addressRemoteRtpUdp;
	sockaddr_in addressLocalRtcpUdp;
	sockaddr_in addressRemoteRtcpUdp;
			
	char localName[MAXHOSTNAMELEN];
	bool m_bConnectionReady;
};

#endif // _CONNECTION_H_
