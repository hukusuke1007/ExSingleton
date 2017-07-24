// ExSingleton.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include  <thread>
#include  "ex_singleton.h"
#include  "logout.h"

using namespace std;
using namespace hukusuke;

/* シングルトンをコールする処理. */
void work_process() {

	// ログ出力
	LOG_OUTPUT("work_process thread_id[%d]", this_thread::get_id());

	// シングルトンクラスを呼び出す.
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

	// ログ出力
	LOG_OUTPUT("Terminate.");

	return 0;
}

