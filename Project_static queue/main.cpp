#include <iostream>
#include "staticQueue.h"
#include <Windows.h>
#include <string>
#include <thread>
#pragma comment(lib, "winmm.lib")
using namespace std;

void Lejatszo()
{
	cout << "A lejatszasi lista: " << endl;
	cout << " --------------------- " << endl;
	cout << "1. Tom Odell - Another Love" << endl;
	cout << "2. Tom Odell - Grow Old With Me" << endl;
	cout << "3. Abba - The winner takes it all" << endl;
	cout << "4. Abba - Chiquitita" << endl;
	cout << "5. Pink Floyd - Us and Them" << endl;
	cout << "6. Pink Floyd - The Great Gig In The Sky" << endl;
	cout << "7. The Beatles - Eleanor Rigby" << endl;
	cout << "8. Harry Styles - Golden" << endl;
	cout << "9. Harry Styles - She" << endl;
	cout << "10. John Lenon - Imagine" << endl<<endl;
}

void Playlist(sQueue*& Queue)
{
	cout << "Valassz, majd nyomd meg a 'q' billentyut" << endl;
	string szam;
	while (szam != "q" and !Overload(Queue))
	{
		cin >> szam;
		int h = 1;
		int nr = 0;
		if (szam != "q")
		{
			for (int i = 0; i < szam.length(); i++)
			{
				if (isdigit(szam[i]))
				{
					nr = nr * h + (szam[i] - '0');
					h *= 10;
				}
			}
			if (nr > 10 or nr < 1)
			{
				cout << "Nincs ilyen sorszamu zene!" << endl;
			}
			else
			{
				Push(Queue, nr);
			}
		}
	}
}

void AddToPlaylist(sQueue* Queue)
{
	if (!Overload(Queue))
	{
		string szam;
		cin >> szam;
		if (szam != "q")
		{
			int h = 1, nr = 0;
			for (int i = 0; i < szam.length(); i++)
			{
				if (isdigit(szam[i]))
				{
					nr = nr * h + (szam[i] - '0');
					h *= 10;
				}
			}
			if (nr > 10 or nr < 1)
			{
				cout << "Nincs ilyen sorszamu zene!" << endl;
			}
			else
			{
				Push(Queue, nr);
			}
		}
	}
}

void Title(int k, unsigned long long& duration)
{
	if (k == 1)
	{
		cout << "Tom Odell - Another Love" << endl;
		duration = 241800;
	}

	else if (k == 2)
	{
		cout << "Tom Odell - Grow Old With Me" << endl;
		duration = 192000;
	}

	else if (k == 3)
	{
		cout << "Abba - The winner takes it all" << endl;
		duration = 273000;
	}

	else if (k == 4)
	{
		cout << "Abba - Chiquitita" << endl;
		duration = 315600;
	}

	else if (k == 5)
	{
		cout << "Pink Floyd - Us and Them" << endl;
		duration = 449400;
	}

	else if (k == 6)
	{
		cout << "Pink Floyd - The Great Gig In The Sky" << endl;
		duration = 265800;
	}

	else if (k == 7)
	{
		cout << "The Beatles - Eleanor Rigby" << endl;
		duration = 124800;
	}

	else if (k == 8)
	{
		cout << "Harry Styles - Golden" << endl;
		duration = 196800;
	}

	else if (k == 9)
	{
		cout << "Harry Styles - She" << endl;
		duration = 361200;
	}

	else if (k == 10)
	{
		cout << "John Lenon - Imagine" << endl;
		duration = 183600;
	}
}

void Start(wstring name)
{
	PlaySound(name.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

void Play(sQueue* Queue)
{
	if (!Overload(Queue))
	{
		cout << "A kert sorrend:" << endl;
		Print(Queue);

		while (!isEmpty(Queue))
		{
			int k = Get(Queue);
			Pop(Queue);
			unsigned long long duration = 0;
			Title(k,duration);
			wstring zene = to_wstring(k) + L".wav";
			unsigned long long starttime = GetTickCount();
			thread Soundthread(Start, zene);
			while (1)
			{
				
				if (GetAsyncKeyState('A') & 0x8000)
				{
					AddToPlaylist(Queue);
				}
				if (GetAsyncKeyState('N') & 0x8000)
				{
					PlaySound(0, 0, 0);
					this_thread::sleep_for(std::chrono::seconds(1/2));
					break;
				}
				
				unsigned long long time = GetTickCount() - starttime;
				if (time>= duration)
				{
					this_thread::sleep_for(std::chrono::seconds(1/2));
					break;
				}
				
			}
			Soundthread.join();
			
		}
		if (isEmpty(Queue))
		{
			cout << "A lejatszasi lista veget ert!" << endl;
		}
	}
}

int main()
{
	cout << "Udvozol a ZeneGép!" << endl << endl;
	cout << "Hasznalat: " << endl;
	cout << "N - kovetkezo" << endl << "A - hozzaad" << endl << endl;;
	Lejatszo();
	static sQueue* Queue = Create(10);
	Playlist(Queue);
	Play(Queue);
	Destroy(Queue);
	return 0;
}