#include "KeyController.h"

namespace KeyHook {
	IKeyController* KeyController::up(WORD vkCode) {
		m_inputQueue->push(vkCode, UP);
		return this;
	}
	IKeyController* KeyController::down(WORD vkCode) {
		m_inputQueue->push(vkCode, DOWN);
		return this;
	}
	IKeyController* KeyController::click(WORD vkCode) {
		m_inputQueue->push(vkCode, DOWN);
		m_inputQueue->push(vkCode, UP);
		return this;
	}
	IKeyController* KeyController::downCtrl() {
		m_inputQueue->push(VK_LCONTROL, DOWN);
		return this;
	}
	IKeyController* KeyController::upCtrl() {
		m_inputQueue->push(VK_LCONTROL, UP);
		return this;
	}
	IKeyController* KeyController::downShift() {
		m_inputQueue->push(VK_LSHIFT, DOWN);
		return this;
	}
	IKeyController* KeyController::upShift() {
		m_inputQueue->push(VK_LSHIFT, UP);
		return this;
	}
	IKeyController* KeyController::downWin() {
		m_inputQueue->push(VK_LWIN, DOWN);
		return this;
	}
	IKeyController* KeyController::upWin() {
		m_inputQueue->push(VK_LWIN, UP);
		return this;
	}
}