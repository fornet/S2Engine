// UIMCommand.h
//
#ifndef QTBRIDGE_UIMCOMMAND_H
#define QTBRIDGE_UIMCOMMAND_H

#include "s2Qt_API.h"

#include <string>
#include <functional>

namespace s2 {
namespace Qt {


class S2QT_API UIMCommand
{
public:
	UIMCommand()
	{}

	UIMCommand( const std::string &activator, const std::function<void()> &cb )
	{
		_callback  = cb;
		_activator = activator;
	}


	std::string activator() const { return _activator; }

	void execute() { if( _callback ) _callback(); }

private:
	std::string           _activator;
	std::function<void()> _callback;
};

}
}


#endif // !GUITOOLS_GUICOMMAND_H
