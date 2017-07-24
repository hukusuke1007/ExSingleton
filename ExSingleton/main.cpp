// ExSingleton.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include  <thread>
#include  "ex_singleton.h"
#include  "logout.h"

using namespace std;
using namespace hukusuke;

/* �V���O���g�����R�[�����鏈��. */
void work_process() {

	// ���O�o��
	LOG_OUTPUT("work_process thread_id[%d]", this_thread::get_id());

	// �V���O���g���N���X���Ăяo��.
	ex_singleton& tmp = ex_singleton::get_instance();
	tmp.start();
}

/* main function. */
int main(void) {

	thread t1(work_process);
	thread t2(work_process);
	thread t3(work_process);

	t1.join();
	t2.join();
	t3.join();

	// ���O�o��
	LOG_OUTPUT("Terminate.");

	return 0;
}

