#include "input.h"

namespace NeovimQt { namespace Input {

Qt::KeyboardModifiers ControlModifier() noexcept
{
	return Qt::MetaModifier;
}

Qt::KeyboardModifiers CmdModifier() noexcept
{
	return Qt::ControlModifier;
}

Qt::Key Key_Control() noexcept
{
	return Qt::Key_Meta;
}

Qt::Key Key_Cmd() noexcept
{
	return Qt::Key_Control;
}

QString GetModifierPrefix(Qt::KeyboardModifiers mod) noexcept
{
	QString modprefix;
	if (mod & CmdModifier()) {
		// This behavior is from MacVim.
		modprefix += "D-";
	}
	if (mod & ControlModifier()) {
		modprefix += "C-";
	}
	if (mod & Qt::ShiftModifier) {
		modprefix += "S-";
	}
	if (mod & Qt::AltModifier) {
		modprefix += "A-";
	}

	return modprefix;
}

} } // namespace NeovimQt::Input