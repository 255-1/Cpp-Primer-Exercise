#include <string>
#include <set>
class Folder;
class Message {
	friend void swap(Message& lhs, Message& rhs);
	friend class Folder;
public:
	explicit Message(const std::string& str = "") :
		contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message&& m) noexcept;
	Message& operator=(Message&&)noexcept;
	~Message();
	//从Folder集合中添加和删除Message
	void save(Folder&);
	void remove(Folder&);

	void print_debug();
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFldr(Folder* f) { folders.insert(f); }
	void remFldr(Folder* f) { folders.erase(f); }

	void move_Folders(Message*);
};

void swap(Message& lhs, Message& rhs);

class Folder {
	friend void swap(Folder& lhs, Folder& rhs);
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	Folder(Folder&& f)noexcept;
	Folder& operator=(Folder&&)noexcept;
	~Folder();
	void addMsg(Message* m) { msgs.insert(m); }
	void remMsg(Message* m) { msgs.erase(m); }
	void print_debug();
private:
	std::set<Message*> msgs;
	void add_to_Message(const Folder&);
	void remove_from_Message();
	
	void move_Message(Folder*);
};

void swap(Folder& lhs, Folder& rhs);