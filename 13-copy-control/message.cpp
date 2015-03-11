#include"message.h"

Message::Message(const Message& msg ){
	sptr = msg.sptr;
	(*msg.use)++;
	use = msg.use;
}

Message& Message::operator = (const Message msg){
	(*use)--;
	if((*use) == 0){
		delete sptr;
		delete use;
	}
	sptr = msg.sptr;
	use = msg.use;

	return *this;
}

Message::~Message(){
	if((*use) == 0){
		delete sptr;
		delete use;
	}
}

void Message:;save(Folder& f){
	folders.insert(f);
	f.addMsg(this);
}

void remove(Folder&){
	folders.erase(f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message& msg){
	for(auto f : msg.folders){
		f->addMsg(this);
	}
}

void Message::remove_from_Folders(){
