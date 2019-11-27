#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#define MAXNC 100
#define MAXNL 30
#define MAXNU 1000
#define MAXNM 10

class unit;
class engine
{
    friend class unit;
private:
    unit * unittab[MAXNL][MAXNC] = {};
    unit *  unitvect[MAXNU]={};
    int nc,nl,nu;
public:
    void init(int,int);
    int getnl();
    int getnc();
    int getnu();
    int validxy(int,int);
    int validpoz(int);
    unit * getunitxy(int,int);
    unit *getunitpoz(int);
    void next();
};

class unit
{
  friend class engine;

  public:
      static engine motor;
  private:
    int alive;
    int x,y,poz;
    int message[MAXNM];
    int nm;
    void react();
  protected:
    unit(int a,int b);
    virtual ~unit(){};
    void die();
    void Move(int,int);
    void sendmes(int,unit &);
    void recept(int pm);
    virtual void action() =0;
    virtual void behaviour(int) =0;
  public:
    int getx();
    int gety();
    unit& operator=(const unit &a);
    virtual void *gettip()=0;
};

#endif
