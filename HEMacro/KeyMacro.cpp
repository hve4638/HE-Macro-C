#include <cassert>
#include "KeyMacro.h"

IKeyMacro& KeyMacro::lock(WORD vkCode) {
	assert(0 <= vkCode && vkCode < MAGICFN_RANGE);
	m_keylock[vkCode] = true;
	return *this;
}

IKeyMacro& KeyMacro::unlock(WORD vkCode) {
	assert(0 <= vkCode && vkCode < MAGICFN_RANGE);
	m_keylock[vkCode] = false;
	return *this;
}

IKeyMacro& KeyMacro::sleep(int ms) {
	Sleep(ms);
	return *this;
}

IKeyMacro& KeyMacro::up(WORD vkCode) {
	m_queue->push(vkCode, KeyState::UP);

	return *this;
}
IKeyMacro& KeyMacro::down(WORD vkCode) {
	m_queue->push(vkCode, KeyState::DOWN);

	return *this;
}
IKeyMacro& KeyMacro::click(WORD vkCode) {
	m_queue->push(vkCode, KeyState::DOWN);
	m_queue->push(vkCode, KeyState::UP);

	return *this;
}

IKeyMacro& KeyMacro::downCtrl() {
	m_queue->push(VK_LCONTROL, KeyState::DOWN);
	return *this;
}
IKeyMacro& KeyMacro::upCtrl() {
	m_queue->push(VK_LCONTROL, KeyState::UP);
	return *this;
}
IKeyMacro& KeyMacro::downShift() {
	m_queue->push(VK_LSHIFT, KeyState::DOWN);
	return *this;
}
IKeyMacro& KeyMacro::upShift() {
	m_queue->push(VK_LSHIFT, KeyState::UP);
	return *this;
}
IKeyMacro& KeyMacro::downWin() {
	m_queue->push(VK_LWIN, KeyState::DOWN);
	return *this;
}
IKeyMacro& KeyMacro::upWin() {
	m_queue->push(VK_LWIN, KeyState::UP);
	return *this;
}