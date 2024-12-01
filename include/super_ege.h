#ifdef _MSC_VER
#define API(x) __declspec(dllexport) x
#else
#define API(x) extern "C" x
#endif

API(int) initgraph(int width,int height,bool windowed);
API(void) closegraph();
API(int) getch();
API(void) setcaption(const char*  caption);

API(void) setbkcolor(int r,int g,int b,int a);
API(void) present();