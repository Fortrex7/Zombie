#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{
  pid_t pid = fork();

  if (pid == -1)
  {
    cerr << "Не удалось создать процесс" << endl;
    return 1;
  }
  else if (pid > 0)
  {
    // Выполнение кода родительским процессом
   cout << "Родительский процесс PID: " << getpid() << endl;

    // Родитель спит некоторое время, чтобы можно было проверить состояние зомби
    sleep(30);
  }
  else
  {
    // Выполнение кода дочерним процессом
    cout << "Дочерний процесс. Мой PID: " << getpid() << endl;
    cout << "Я собираюсь завершиться через 30 сек, чтобы можно было проверить состояние зомби" << endl;
    // Дочерний процесс завершается
  }

  return 0;
}
