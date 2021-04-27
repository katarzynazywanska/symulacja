#pragma once
class ResourceBlock
{
private:
	bool if_transmission_error_;
	int what_user_id_;

public:
	ResourceBlock(bool if_error = false, int what_user = 0);
	bool fun_if_error();
};

