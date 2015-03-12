#include <iostream>

using namespace std;

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Laag1
{
 public: virtual ~Laag1 () {}

         virtual void service () = 0;
};

class Laag1Server
{
 public: virtual ~Laag1Server () {}

         virtual void layerRequest () = 0;
};

class Laag1Impl : public Laag1
{
 private: Laag1Server* L1;

 public: virtual void service ()
                        { cout << "Laag 1 start..." << endl;
                          L1->layerRequest();
                          cout << "Laag 1 eindigt..." << endl;
                        }

         virtual void connectHigh (Laag1Server* s) { L1=s; }
};

//---------------------------------------------------------------------------

class Laag2
{
 private: Laag1*  L1;

 public: virtual ~Laag2 () {}

         virtual void service () = 0;

         virtual Laag1* laag1 () { return L1; }

         virtual void connectLow (Laag1* l1) { L1=l1; }
};

class Laag2Server
{
 public: virtual ~Laag2Server () {}

         virtual void layerRequest () = 0;
};

class Laag2Impl : public Laag2, public Laag1Server
{
 private: Laag2Server* L2;

 public: virtual void service ()
                        { cout << "Laag 2 start..." << endl;
                          laag1()->service();
                          cout << "Laag 2 eindigt..." << endl;
                        }

         virtual void layerRequest ()
                        { cout << "Laag 2 start..." << endl;
                          L2->layerRequest();
                          cout << "Laag 2 eindigt..." << endl;
                        }

         virtual void connectHigh (Laag2Server* s) { L2=s; }
};

//---------------------------------------------------------------------------

class Laag3
{
 private: Laag2*  L2;

 public: virtual ~Laag3 () {}

         virtual void service () = 0;

         virtual Laag2* laag2 () { return L2; }

         virtual void connectLow (Laag2* l2) { L2=l2; }
};

class Laag3Impl : public Laag3, public Laag2Server
{
 public: virtual void service ()
                        { cout << "Laag 3 start..." << endl;
                          laag2()->service();
                          cout << "Laag 3 eindigt..." << endl;
                        }
         virtual void layerRequest ()
                        { cout << "Laag 3 start..." << endl;
                          cout << "Laag 3 eindigt..." << endl;
                        }
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

int main( )
{
 Laag1Impl L1;
 Laag2Impl L2;
 Laag3Impl L3;

 L1.connectHigh(&L2);
 L2.connectLow (&L1);
 L2.connectHigh(&L3);
 L3.connectLow (&L2);

 L3.service();

 cin.get();
 return 0;
}

//---------------------------------------------------------------------------

/* Output:

Laag 3 start...
Laag 2 start...
Laag 1 start...
Laag 2 start...
Laag 3 start...
Laag 3 eindigt...
Laag 2 eindigt...
Laag 1 eindigt...
Laag 2 eindigt...
Laag 3 eindigt...

*/