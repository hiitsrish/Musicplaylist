#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

class mu
{
	int sno;
	char song[20];
	char artist[20];
	int year;

public:
	void enter();
	void show();
	int sino()
	{
		return sno;
	}
	char *gn() { return song; }
};

void mu::enter()
{
	cout << "Enter the following details: " << endl;
	cout << "Sno::";
	cin >> sno;
	cout << "Song name:: ";
	gets(song);
	cout << "Artist:: ";
	gets(artist);
	cout << "Year::";
	cin >> year;
	cout << endl;
	cout << endl;
}

void mu::show()
{
	cout << setw(3) << sno << setw(30) << song << setw(30) << artist << setw(5) << year;
	cout << endl
		 << endl;
}

void display()
{
	fstream f;
	mu s;
	f.open("songs.DAT", ios::binary | ios::in);
	while (f.read((char *)&s, sizeof(s)))
	{
		s.show();
	}
	f.close();
}

void create()
{
	fstream f, w;
	int sno;
	w.open("playlist.DAT", ios::binary | ios::out);
	mu s;
	char ch;
	do
	{
		f.open("songs.DAT", ios::binary | ios::in);
		cout << "Enter S.No of your song choice:";
		cin >> sno;
		cout << endl;
		while (f.read((char *)&s, sizeof(s)))
		{
			if (s.sino() == sno)
				w.write((char *)&s, sizeof(s));
		}
		cout << "More songs(y/Y)?";
		cin >> ch;
		cout << endl;
		f.close();
	} while (ch == 'y' || ch == 'Y');
	w.close();
}

void playdis()
{
	fstream f;
	mu s;
	f.open("playlist.DAT", ios::binary | ios::in);
	while (f.read((char *)&s, sizeof(s)))
	{
		s.show();
	}
	f.close();
}
void newdisp()
{
	fstream f, h;
	mu s;
	f.open("edited.DAT", ios::binary | ios::in);
	h.open("playlist.DAT", ios::binary | ios::out);
	while (f.read((char *)&s, sizeof(s)))
	{
		h.write((char *)&s, sizeof(s));
	}
	f.close();
	h.close();
}

void del()
{
	fstream f, h;
	h.open("edited.DAT", ios::binary | ios::out);
	f.open("playlist.DAT", ios::binary | ios::in);
	int i, d = 0;
	mu s;
	cout << "Enter song no. to be deleted::";
	cin >> i;
	while (f.read((char *)&s, sizeof(s)))
	{
		if (s.sino() != i)
		{
			h.write((char *)&s, sizeof(s));
		}
		else
			d++;
	}
	if (!d)
		cout << "Not found" << endl;
	else
		cout << endl
			 << "Deleted" << endl;
	f.close();
	h.close();
	newdisp();
}
void count()
{
	fstream f;
	mu s;
	int c = 0;
	f.open("playlist.DAT", ios::binary | ios::in);
	while (f.read((char *)&s, sizeof(s)))
	{
		c++;
	}
	cout << "THE NO OF SONGS IN YOU PLAYLIST IS:" << c << endl;
	f.close();
}
void add()
{
	fstream f, h;
	h.open("songs.DAT", ios::binary | ios::in);
	f.open("playlist.DAT", ios::binary | ios::app);
	int i, d = 0;
	mu s;
	display();
	cout << "Enter song no. to be added::";
	cin >> i;
	while (h.read((char *)&s, sizeof(s)))
	{
		if (s.sino() == i)
		{
			f.write((char *)&s, sizeof(s));
		}
		else
			d++;
	}
	if (!d)
		cout << "Not found" << endl;
	else
		cout << "ADDED!" << endl;
	f.close();
	h.close();
}

void searchno()
{
	fstream f;
	f.open("playlist.DAT", ios::binary | ios::in);
	int i, d = 0;
	mu s;
	cout << "Enter song no. to be searched::";
	cin >> i;
	while (!d && f.read((char *)&s, sizeof(s)))
	{
		if (s.sino() == i)
		{
			s.show();
			d++;
		}
	}

	if (!d)
		cout << "Song not found!!" << endl;
	f.close();
}

void sort()
{
	fstream f;
	f.open("playlist.DAT", ios::binary | ios::in | ios::out);
	f.seekg(0, ios::end);
	int n = f.tellg() / sizeof(mu);
	mu s, a;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			f.seekg(j * sizeof(mu));
			f.read((char *)&s, sizeof(mu));
			f.read((char *)&a, sizeof(mu));
			if (strcmpi(s.gn(), a.gn()) > 0)
			{
				f.seekp(j * sizeof(mu));
				f.write((char *)&a, sizeof(mu));
				f.write((char *)&s, sizeof(mu));
			}
		}
	f.close();
}

int main()
{
	system("cls");
	int c;
	char r[20];

	system("cls");
	{
		cout << endl
			 << endl
			 << endl
			 << endl
			 << endl
			 << endl
			 << endl
			 << endl
			 << endl
			 << setw(57) << ".______~WELCOME TO SOUNDMIST~ _______." << endl
			 << endl
			 << endl;
		cout << setw(55) << "Press enter to continue further...." << endl;
	}
	getch();
	do
	{
		system("cls");
		cout << endl
			 << endl
			 << endl
			 << endl;
		cout << setw(47) << "1. Create Playlist" << endl;
		cout << setw(45) << "2. View Playlist" << endl;
		cout << setw(46) << "3. Delete a song " << endl;
		cout << setw(43) << "4. Add a song " << endl;
		cout << setw(48) << "5.Sort by song name" << endl;
		cout << setw(53) << "6. Search by song number" << endl;
		cout << setw(36) << "7. Exit" << endl
			 << endl
			 << endl;
		cout << "Enter your choice::";
		cin >> c;
		switch (c)
		{

		case 1:
			system("cls");
			{
				cout << endl
					 << setw(50) << "GIVE YOUR PLAYLIST A NAME::";
				cin >> r;
				display();
				create();
				getch();
				system("cls");
				cout << endl
					 << endl
					 << endl
					 << endl
					 << setw(30) << "PLAYLIST"
					 << " " << r << " "
					 << " CREATED!!" << endl
					 << endl
					 << endl;
				cout << setw(55);
				count();
				getch();
			}
			getch();
			break;
		case 2:
			system("cls");
			{
				cout << "Playlist Name::" << r << endl
					 << endl;
				playdis();
			}
			getch();
			break;
		case 3:
			system("cls");
			playdis();
			del();
			playdis();
			count();
			getch();
			break;
		case 4:
			system("cls");
			add();
			playdis();
			count();
			getch();
			break;
		case 5:
			system("cls");
			sort();
			cout << endl
				 << endl
				 << "Your playlist has been sorted!" << endl
				 << endl;
			playdis();
			getch();
			break;
		case 6:
			system("cls");
			searchno();
			getch();
			break;
		}

	} while (c != 7);
	getch();
	getch();
	return 0;
}
