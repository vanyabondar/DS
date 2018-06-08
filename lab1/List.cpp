
void Add(List **L, int x, string s)
{
	List * r = new List;
	r->Data.x = x;
	r->Data.s = s;
	r->Next = nullptr;
	if (*L)
	{
		List * Tail = *L;
		while (Tail->Next)
			Tail = Tail->Next;
		Tail->Next = r;
	}
	else
		*L = r;
}

void Write(List * L)
{
	for (List * Tail = L; Tail; Tail = Tail->Next)
		cout << Tail->Data.x << ' ' << Tail->Data.s << endl;
	cout << endl;
}

void Clear(List * L)
{
	if (!L)
		return;
	List * Tail = L;
	while (Tail->Next)
	{
		L = Tail;
		Tail = Tail->Next;
		delete L;
	}
}


void Pasting(List **L1, List ** L2)
{
	if (*L1)
	{
		List * Tail = *L1;
		while (Tail->Next)
			Tail = Tail->Next;
		Tail->Next = *L2;
	}
	else
		*L1 = *L2;
	*L2 = nullptr;

}