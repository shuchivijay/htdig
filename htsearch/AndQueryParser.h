#ifndef _AndQueryParser_h_
#define _AndQueryParser_h_

//
// AndQueryParser.h
//
// AndQueryParser: a simple query parser for 'all words' queries
//
// Part of the ht://Dig package   <http://www.htdig.org/>
// Copyright (c) 1995-2000 The ht://Dig Group
// For copyright details, see the file COPYING in your distribution
// or the GNU Public License version 2 or later
// <http://www.gnu.org/copyleft/gpl.html>
//
// $Id: AndQueryParser.h,v 1.2 2002/02/02 18:18:13 ghutchis Exp $
//

#include "SimpleQueryParser.h"
#include "AndQuery.h"

class AndQueryParser : public SimpleQueryParser
{
public:
	AndQueryParser() {}

private:
	OperatorQuery *MakeQuery()
	{
		return new AndQuery;
	}
};

#endif