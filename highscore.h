//Declaring integers
int point = 0;
int res = 0;
string rst;
//Declaring number's font! :P
SDL_Rect fontrect1, fontrect2, hsrect;
//Declaring tect's color
SDL_Color textColor1 = {255, 255, 255};
//Declaring font's surafce
SDL_Surface* fontsurface1, *fontsurface2, *highscreen, *highscreen1;
//Stuffs to convert integer to const char!
std::stringstream strm, strm1;
//File handing function
int wrhs(){
	//Declaring highscore integer!
	int hs;
	//Defining font's rectangle co-ordinantes
	fontrect1.x = 415;
	fontrect1.y = 70;
	fontrect2.x = 415;
	fontrect2.y = 350;
	hsrect.x = 310;
	hsrect.y = 200;
	//ofstream and ifstream for file handling
	ofstream myfile;
	ifstream mf1;
	//Integer conversion stuffs
	strm << point;
	//Defining font and font's surface
	highscreen1 = IMG_Load("hsc.png");
	TTF_Font *font1 = TTF_OpenFont( "arial.ttf", 60 );
	fontsurface1 = TTF_RenderText_Solid(font1, strm.str().c_str() , textColor1);
	fontsurface2 = TTF_RenderText_Solid(font1, strm1.str().c_str() , textColor1);
	mf1.open("highscore.txt"); //Opens highscore.txt file
	mf1>>hs; //inputs hs  integer to mf1 ifstream
	mf1.close(); //Closes mf1
  myfile.open ("highscore.txt");//Opens highscore.txt as myfile ofstream
	//File handling stuffs
	if(hs <= point)
  hs = point;
  system("clear");
  cout<<"Highscore = "<<hs<<endl;
  cout<<"Your score is "<<point<<endl;
		if(res == 1){
  	cout<<"Enter 'reset' to reset highscore, or any other key to quit"<<endl;
  	cin>>rst;
  	if(rst=="reset"){
  		hs = 0;
  		cout<<"Highscore has been reset!"<<endl;
  		}
  	else
  		cout<<"Highscore hasn't been reset!"<<endl;
  }
  myfile<<hs;

  myfile.close();
	//Integer to constant char conversion stuffs
	strm<<point;
	strm1.str("");
	strm1.clear();
	strm1<<hs;
}
