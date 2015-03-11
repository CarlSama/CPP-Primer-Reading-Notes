#pragma once

#include<memory>

class Message{
	friend class Folder;

	public:
		explicit Message(const string *str = nullptr):sptr(str),used(new int(1)){};
		Message(const Message& );
		Message& operator = (const Message);

		~Message();

		void save(Folder&);
		void remove(Folder&);
	private:
		string *sptr;
		int *use;
		set<Folder*> folders;
		void add_to_Folders(const Message&);
		void remove_from_Folders();
};
