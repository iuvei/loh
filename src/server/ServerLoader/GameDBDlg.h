//////////////////////////////////////////////////////////////////
//   The Legend of Heroes                                       //
//   Copyright(C) LH Studio. All Rights Reserved                //
//                                                              //
//   Header File : GameDBDlg.h                                  //
//   Author : jaredz@outlook.com                                //
//   Create : 2012-12-01     version 0.0.0.1                    //
//   Update : 2015-11-25     version 0.0.0.5                    //
//   Detail : 游戏DB服务器界面对话框                             //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef __GAMEDB_DLG_H__
#define __GAMEDB_DLG_H__

#pragma once

#include "CommonDlg.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 游戏DB服务器界面对话框 
class CGameDBDlg : public CCommonDlg
{
public:
	CGameDBDlg(void);
	virtual ~CGameDBDlg(void);

	DECLARE_DLG_ID_WND_EXCHANGE( CGameDBDlg )
protected :
	virtual LRESULT OnInitDialog(void) OVERRIDE;

	LRESULT OnSize(WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	BEGIN_INLINE_MSG_MAP( CGameDBDlg )
	// {{ --
		MSG_HANDLER(WM_SIZE, OnSize)
	// --}}
	END_CHAIN_MSG_MAP( CXDlg )
private:
	virtual void OnLive(bool bStart) OVERRIDE;
	virtual void OnLink(Int nServerIndex, uintptr_t utParam) OVERRIDE;
	virtual void OnUpdate(Int nServerIndex, uintptr_t utParam) OVERRIDE;
	virtual void OnSync(Int nServerIndex, uintptr_t utParam) OVERRIDE;
	virtual void OnSync(Int nServerIndex, CStream& Stream) OVERRIDE;
	virtual void OnUnlink(Int nServerIndex, uintptr_t utParam) OVERRIDE;

	virtual void UpdateServerInfo(void) OVERRIDE;

	virtual CXListView* GetListView(Int nServerIndex) OVERRIDE;
private:
	UInt                   m_uGameDBOnline; 
	UInt                   m_uGameDBAll;    
	UInt                   m_uGameDBBusy;   
	UInt                   m_uGameCount;    
	UInt                   m_uGameOnline;   
	UInt                   m_uGameAll;      
	UInt                   m_uGateCount;    
	UInt                   m_uGateOnline;	
	UInt                   m_uGateAll;      
	CXStatic               m_ListenGame;
	CXStatic               m_ListenGate;
	CXStatic               m_ServerInfo;
	CXListView             m_GameSvr;
	CXListView             m_GateSvr;
};

#endif // __GAMEDB_DLG_H__
