#pragma once
#include "../css-math/matrix.h"
#include "../css-math/vec.h"
#include "../css-math/color.h"

struct recvprop;

struct recvtable
{
	recvprop		*m_pProps;
	int				m_nProps;
	BYTE            Pad[4];
	char			*m_pNetTableName;
};

struct recvprop
{
	char	  *m_pVarName;
	BYTE      PPad[36];
	recvtable *m_pDataTable;
	int		  m_Offset;
	BYTE      Pad[12];
};
struct clientclass
{
	BYTE          Pad[12];
	recvtable*	  GetTable;
	clientclass*  NextClass;
};

class chlclient
{
public:

	clientclass* allclasses()
	{
		typedef clientclass*(__thiscall* origfn)(PVOID);
		return (*(origfn**)this)[8](this);
	}
};