#include "Message.h"
#include <vector>
#include <string>
#include <set>
#include <iostream>

void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message& m) {
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders() {
	for (auto f : folders)
		f->remMsg(this);
}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Message::Message(const Message& m):
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message::Message(Message&& m)noexcept
:contents(std::move(m.contents))
{
	move_Folders(&m);
}

Message& Message::operator=(Message&& rhs)noexcept
{
	if (this != &rhs)
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	std::cout << "移动赋值" << std::endl;
	return *this;
}

void swap(Message& lhs, Message& rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	//交换contents和Folder指针
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	//将Message添加进Folder中
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

void Message::print_debug()
{
	std::cout << contents << std::endl;
}

//************************Message Implement****************
void Folder::add_to_Message(const Folder& f)
{
	for (auto m : f.msgs)
		m->addFldr(this);
}

Folder::Folder(const Folder& f)
	: msgs(f.msgs)
{
	add_to_Message(f);
}

void Folder::remove_from_Message()
{
	for (auto m : msgs)
		m->remFldr(this);
}

void Folder::move_Message(Folder* f)
{
	msgs = std::move(f->msgs);
	for (auto m : msgs)
	{
		m->remFldr(f);
		m->addFldr(this);
	}
	f->msgs.clear();
}

Folder& Folder::operator=(Folder&& rhs)noexcept
{
	if (this != &rhs)
	{
		remove_from_Message();
		move_Message(&rhs);
	}
	std::cout << "Message member moved " << std::endl;
	return *this;
}

Folder::~Folder()
{
	remove_from_Message();
}

Folder& Folder::operator=(const Folder& rhs)
{
	remove_from_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}

Folder::Folder(Folder&& f)noexcept
{
	move_Message(&f);
}

void Folder::print_debug()
{
	for (auto m : msgs)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}

void swap(Folder& lhs, Folder& rhs)
{
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();

	swap(lhs.msgs, rhs.msgs);

	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}
