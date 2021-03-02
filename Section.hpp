#ifndef PLAYER_SECTION
#define PLAYER_SECTION

class Section {
	private:
		int x = 0;
		int y = 0;
	public:
		int GetX();
		int GetY();
		void SetX(int x);
		void SetY(int y);
		void SetPosition(int x, int y);
		void SetPosition(int x, int y, int width, int height);//reallocate based on the size of the body part
};

#endif
