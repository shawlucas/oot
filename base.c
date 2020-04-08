typedef unsigned long size_t;
float sinf(float);
double sin(double);
float cosf(float);
double cos(double);
float sqrtf(float f);
typedef signed char s8;
typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long int s64;
typedef unsigned long long int u64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef float f32;
typedef double f64;
typedef long int Mtx_t[4][4];
typedef union {
    Mtx_t m;
    long long int forc_structure_alignment;
} Mtx;
typedef float MtxF_t[4][4];
typedef union {
    MtxF_t mf;
    struct
    {
        float xx, xy, xz, xw,
              yx, yy, yz, yw,
              zx, zy, zz, zw,
              wx, wy, wz, ww;
    };
} MtxF;
typedef u32 OSIntMask;
OSIntMask osGetIntMask(void);
OSIntMask osSetIntMask(OSIntMask);
u32 osGetCount(void);
u32 osDpGetStatus(void);
void osDpSetStatus(u32 status);
typedef s32 OSPri;
typedef s32 OSId;
typedef union
{
    struct {f32 f_odd; f32 f_even;} f;
} __OSfp;
typedef struct
{
              u64 at, v0, v1, a0, a1, a2, a3;
              u64 t0, t1, t2, t3, t4, t5, t6, t7;
              u64 s0, s1, s2, s3, s4, s5, s6, s7;
              u64 t8, t9, gp, sp, s8, ra;
              u64 lo, hi;
              u32 sr, pc, cause, badvaddr, rcp;
              u32 fpcsr;
    __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;
typedef struct
{
    u32 flag;
    u32 count;
    u64 time;
} __OSThreadprofile_s;
typedef struct OSThread_s
{
             struct OSThread_s *next;
             OSPri priority;
             struct OSThread_s **queue;
             struct OSThread_s *tlnext;
             u16 state;
             u16 flags;
             OSId id;
             int fp;
             __OSThreadprofile_s *thprof;
             __OSThreadContext context;
} OSThread;
void osCreateThread(OSThread *thread, OSId id, void (*entry)(void *),
    void *arg, void *sp, OSPri pri);
OSId osGetThreadId(OSThread *thread);
OSPri osGetThreadPri(OSThread *thread);
void osSetThreadPri(OSThread *thread, OSPri pri);
void osStartThread(OSThread *thread);
void osStopThread(OSThread *thread);
extern u32 osVirtualToPhysical(void*);
extern void* osPhysicalToVirtual(u32);
typedef u32 OSEvent;
typedef void * OSMesg;
typedef struct OSMesgQueue_s {
 OSThread *mtqueue;
 OSThread *fullqueue;
 s32 validCount;
 s32 first;
 s32 msgCount;
 OSMesg *msg;
} OSMesgQueue;
extern void osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern s32 osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32 osJamMesg(OSMesgQueue *, OSMesg, s32);
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern void osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);
typedef u64 OSTime;
typedef struct OSTimer_s
{
 struct OSTimer_s *next;
 struct OSTimer_s *prev;
 OSTime interval;
 OSTime value;
 OSMesgQueue *mq;
 OSMesg msg;
} OSTimer;
OSTime osGetTime(void);
int osSetTimer(OSTimer *timer, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg);
void osStopTimer(OSTimer *timer);
typedef struct
{
               u32 type;
               u32 flags;
               u64* ucode_boot;
               u32 ucode_boot_size;
               u64* ucode;
               u32 ucode_size;
               u64* ucode_data;
               u32 ucode_data_size;
               u64* dram_stack;
               u32 dram_stack_size;
               u64* output_buff;
               u64* output_buff_size;
               u64* data_ptr;
               u32 data_size;
               u64* yield_data_ptr;
               u32 yield_data_size;
} OSTask_t;
typedef union
{
    OSTask_t t;
    long long int force_structure_alignment;
} OSTask;
typedef u32 OSYieldResult;
void osSpTaskLoad(OSTask *task);
void osSpTaskStartGo(OSTask *task);
void osSpTaskYield(void);
OSYieldResult osSpTaskYielded(OSTask *task);
void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect,
    float near, float far, float scale);
void guPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near,
    float far, float scale);
typedef struct
{
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;
typedef struct
{
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;
typedef struct
{
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;
typedef struct {
              f32 factor;
              u16 offset;
              u32 scale;
} __OSViScale;
typedef struct
{
               u16 state;
               u16 retraceCount;
               void* buffer;
               OSViMode *modep;
               u32 features;
               OSMesgQueue *mq;
               OSMesg *msg;
               __OSViScale x;
               __OSViScale y;
} OSViContext;
void osCreateViManager(OSPri pri);
void osViSetMode(OSViMode *mode);
void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount);
void osViBlack(u8 active);
void osViSetSpecialFeatures(u32 func);
void osViSwapBuffer(void *vaddr);
extern OSViMode osViModeTable[];
typedef struct
{
               u32 errStatus;
               void *dramAddr;
               void *C2Addr;
               u32 sectorSize;
               u32 C1ErrNum;
               u32 C1ErrSector[4];
} __OSBlockInfo;
typedef struct
{
               u32 cmdType;
               u16 transferMode;
               u16 blockNum;
               s32 sectorNum;
               u32 devAddr;
               u32 bmCtlShadow;
               u32 seqCtlShadow;
               __OSBlockInfo block[2];
} __OSTranxInfo;
typedef struct OSPiHandle_s
{
               struct OSPiHandle_s *next;
               u8 type;
               u8 latency;
               u8 pageSize;
               u8 relDuration;
               u8 pulse;
               u8 domain;
               u32 baseAddress;
               u32 speed;
               __OSTranxInfo transferInfo;
} OSPiHandle;
typedef struct
{
    u8 type;
    u32 address;
} OSPiInfo;
typedef struct
{
               u16 type;
               u8 pri;
               u8 status;
               OSMesgQueue *retQueue;
} OSIoMesgHdr;
typedef struct
{
             OSIoMesgHdr hdr;
             void *dramAddr;
             u32 devAddr;
             size_t size;
             OSPiHandle* piHandle;
} OSIoMesg;
s32 osPiStartDma(OSIoMesg *mb, s32 priority, s32 direction,
                 u32 devAddr, void *vAddr, size_t nbytes, OSMesgQueue *mq);
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf,
                       s32 cmdMsgCnt);
OSMesgQueue *osPiGetCmdQueue(void);
s32 osPiWriteIo(u32 devAddr, u32 data);
s32 osPiReadIo(u32 devAddr, u32 *data);
typedef struct
{
    u32 initialized;
    OSThread *mgrThread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *eventQueue;
    OSMesgQueue *acccessQueue;
    s32 (*piDmaCallback)(s32, u32, void*, size_t);
    s32 (*epiDmaCallback)(OSPiHandle *, s32, u32, void *, size_t);
} OSMgrArgs;
typedef struct
{
    OSMesgQueue* queue;
    OSMesg msg;
} __osHwInt;
typedef struct
{
    OSMesgQueue* queue;
    OSMesg msg;
} __OSEventState;
u32 __osProbeTLB(void *);
s32 __osDisableInt(void);
OSThread *__osPopThread(OSThread**);
void __osCleanupThread(void);
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 unsigned char cn[4];
} Vtx_t;
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 signed char n[3];
 unsigned char a;
} Vtx_tn;
typedef union {
    Vtx_t v;
    Vtx_tn n;
    long long int force_structure_alignment;
} Vtx;
typedef struct {
  void *SourceImagePointer;
  void *TlutPointer;
  short Stride;
  short SubImageWidth;
  short SubImageHeight;
  char SourceImageType;
  char SourceImageBitSize;
  short SourceImageOffsetS;
  short SourceImageOffsetT;
  char dummy[4];
} uSprite_t;
typedef union {
  uSprite_t s;
  long long int force_structure_allignment[3];
} uSprite;
typedef struct {
 unsigned char flag;
 unsigned char v[3];
} Tri;
typedef struct {
 short vscale[4];
 short vtrans[4];
} Vp_t;
typedef union {
    Vp_t vp;
    long long int force_structure_alignment;
} Vp;
typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
  signed char dir[3];
  char pad3;
} Light_t;
typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
} Ambient_t;
typedef struct {
  int x1,y1,x2,y2;
} Hilite_t;
typedef union {
    Light_t l;
    long long int force_structure_alignment[2];
} Light;
typedef union {
    Ambient_t l;
    long long int force_structure_alignment[1];
} Ambient;
typedef struct {
    Ambient a;
    Light l[7];
} Lightsn;
typedef struct {
    Ambient a;
    Light l[1];
} Lights0;
typedef struct {
    Ambient a;
    Light l[1];
} Lights1;
typedef struct {
    Ambient a;
    Light l[2];
} Lights2;
typedef struct {
    Ambient a;
    Light l[3];
} Lights3;
typedef struct {
    Ambient a;
    Light l[4];
} Lights4;
typedef struct {
    Ambient a;
    Light l[5];
} Lights5;
typedef struct {
    Ambient a;
    Light l[6];
} Lights6;
typedef struct {
    Ambient a;
    Light l[7];
} Lights7;
typedef struct {
    Light l[2];
} LookAt;
typedef union {
    Hilite_t h;
    long int force_structure_alignment[4];
} Hilite;
typedef struct {
 int cmd:8;
 unsigned int par:8;
 unsigned int len:16;
 unsigned int addr;
} Gdma;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri tri;
} Gtri;
typedef struct {
  int cmd:8;
  int pad1:24;
  int pad2:24;
  unsigned char param:8;
} Gpopmtx;
typedef struct {
  int cmd:8;
  int pad0:8;
  int mw_index:8;
  int number:8;
  int pad1:8;
  int base:24;
} Gsegment;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeL;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeH;
typedef struct {
  unsigned char cmd;
  unsigned char lodscale;
  unsigned char tile;
  unsigned char on;
  unsigned short s;
  unsigned short t;
} Gtexture;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri line;
} Gline3D;
typedef struct {
  int cmd:8;
  int pad1:24;
  short int pad2;
  short int scale;
} Gperspnorm;
typedef struct {
                int cmd:8;
                unsigned int fmt:3;
                unsigned int siz:2;
                unsigned int pad:7;
                unsigned int wd:12;
                unsigned int dram;
} Gsetimg;
typedef struct {
  int cmd:8;
  unsigned int muxs0:24;
  unsigned int muxs1:32;
} Gsetcombine;
typedef struct {
  int cmd:8;
  unsigned char pad;
  unsigned char prim_min_level;
  unsigned char prim_level;
  unsigned long color;
} Gsetcolor;
typedef struct {
  int cmd:8;
  int x0:10;
  int x0frac:2;
  int y0:10;
  int y0frac:2;
  unsigned int pad:8;
  int x1:10;
  int x1frac:2;
  int y1:10;
  int y1frac:2;
} Gfillrect;
typedef struct {
  int cmd:8;
  unsigned int fmt:3;
  unsigned int siz:2;
  unsigned int pad0:1;
  unsigned int line:9;
  unsigned int tmem:9;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int palette:4;
  unsigned int ct:1;
  unsigned int mt:1;
  unsigned int maskt:4;
  unsigned int shiftt:4;
  unsigned int cs:1;
  unsigned int ms:1;
  unsigned int masks:4;
  unsigned int shifts:4;
} Gsettile;
typedef struct {
  int cmd:8;
  unsigned int sl:12;
  unsigned int tl:12;
  int pad:5;
  unsigned int tile:3;
  unsigned int sh:12;
  unsigned int th:12;
} Gloadtile;
typedef Gloadtile Gloadblock;
typedef Gloadtile Gsettilesize;
typedef Gloadtile Gloadtlut;
typedef struct {
  unsigned int cmd:8;
  unsigned int xl:12;
  unsigned int yl:12;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int xh:12;
  unsigned int yh:12;
  unsigned int s:16;
  unsigned int t:16;
  unsigned int dsdx:16;
  unsigned int dtdy:16;
} Gtexrect;
typedef struct {
    unsigned long w0;
    unsigned long w1;
    unsigned long w2;
    unsigned long w3;
} TexRect;
typedef struct {
 unsigned int w0;
 unsigned int w1;
} Gwords;
typedef union {
 Gwords words;
 Gdma dma;
 Gtri tri;
 Gline3D line;
 Gpopmtx popmtx;
 Gsegment segment;
 GsetothermodeH setothermodeH;
 GsetothermodeL setothermodeL;
 Gtexture texture;
 Gperspnorm perspnorm;
 Gsetimg setimg;
 Gsetcombine setcombine;
 Gsetcolor setcolor;
 Gfillrect fillrect;
 Gsettile settile;
 Gloadtile loadtile;
 Gsettilesize settilesize;
 Gloadtlut loadtlut;
        long long int force_structure_alignment;
} Gfx;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int gain : 16;
    unsigned int addr;
} Aadpcm;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int gain : 16;
    unsigned int addr;
} Apolef;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int pad1 : 16;
    unsigned int addr;
} Aenvelope;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int dmem : 16;
    unsigned int pad2 : 16;
    unsigned int count : 16;
} Aclearbuff;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int pad2 : 16;
    unsigned int inL : 16;
    unsigned int inR : 16;
} Ainterleave;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 24;
    unsigned int addr;
} Aloadbuff;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int pad1 : 16;
    unsigned int addr;
} Aenvmixer;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int gain : 16;
    unsigned int dmemi : 16;
    unsigned int dmemo : 16;
} Amixer;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int dmem2 : 16;
    unsigned int addr;
} Apan;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int pitch : 16;
    unsigned int addr;
} Aresample;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int pad1 : 16;
    unsigned int addr;
} Areverb;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 24;
    unsigned int addr;
} Asavebuff;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 24;
    unsigned int pad2 : 2;
    unsigned int number : 4;
    unsigned int base : 24;
} Asegment;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int dmemin : 16;
    unsigned int dmemout : 16;
    unsigned int count : 16;
} Asetbuff;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int vol : 16;
    unsigned int voltgt : 16;
    unsigned int volrate : 16;
} Asetvol;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int dmemin : 16;
    unsigned int dmemout : 16;
    unsigned int count : 16;
} Admemmove;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int count : 16;
    unsigned int addr;
} Aloadadpcm;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int pad2 : 16;
    unsigned int addr;
} Asetloop;
typedef struct
{
    unsigned int w0;
    unsigned int w1;
} Awords;
typedef union {
    Awords words;
    Aadpcm adpcm;
    Apolef polef;
    Aclearbuff clearbuff;
    Aenvelope envelope;
    Ainterleave interleave;
    Aloadbuff loadbuff;
    Aenvmixer envmixer;
    Aresample resample;
    Areverb reverb;
    Asavebuff savebuff;
    Asegment segment;
    Asetbuff setbuff;
    Asetvol setvol;
    Admemmove dmemmove;
    Aloadadpcm loadadpcm;
    Amixer mixer;
    Asetloop setloop;
    long long int force_union_align;
} Acmd;
typedef short ADPCM_STATE[16];
typedef short POLEF_STATE[4];
typedef short RESAMPLE_STATE[16];
typedef short ENVMIX_STATE[40];
typedef struct {
  u16 imageX;
  u16 imageW;
  s16 frameX;
  u16 frameW;
  u16 imageY;
  u16 imageH;
  s16 frameY;
  u16 frameH;
  u64 *imagePtr;
  u16 imageLoad;
  u8 imageFmt;
  u8 imageSiz;
  u16 imagePal;
  u16 imageFlip;
  u16 tmemW;
  u16 tmemH;
  u16 tmemLoadSH;
  u16 tmemLoadTH;
  u16 tmemSizeW;
  u16 tmemSize;
} uObjBg_t;
typedef struct {
  u16 imageX;
  u16 imageW;
  s16 frameX;
  u16 frameW;
  u16 imageY;
  u16 imageH;
  s16 frameY;
  u16 frameH;
  u64 *imagePtr;
  u16 imageLoad;
  u8 imageFmt;
  u8 imageSiz;
  u16 imagePal;
  u16 imageFlip;
  u16 scaleW;
  u16 scaleH;
  s32 imageYorig;
  u8 padding[4];
} uObjScaleBg_t;
typedef union {
  uObjBg_t b;
  uObjScaleBg_t s;
  long long int force_structure_alignment;
} uObjBg;
typedef struct {
  s16 objX;
  u16 scaleW;
  u16 imageW;
  u16 paddingX;
  s16 objY;
  u16 scaleH;
  u16 imageH;
  u16 paddingY;
  u16 imageStride;
  u16 imageAdrs;
  u8 imageFmt;
  u8 imageSiz;
  u8 imagePal;
  u8 imageFlags;
} uObjSprite_t;
typedef union {
  uObjSprite_t s;
  long long int force_structure_alignment;
} uObjSprite;
typedef struct {
  s32 A, B, C, D;
  s16 X, Y;
  u16 BaseScaleX;
  u16 BaseScaleY;
} uObjMtx_t;
typedef union {
  uObjMtx_t m;
  long long int force_structure_alignment;
} uObjMtx;
typedef struct {
  s16 X, Y;
  u16 BaseScaleX;
  u16 BaseScaleY;
} uObjSubMtx_t;
typedef union {
  uObjSubMtx_t m;
  long long int force_structure_alignment;
} uObjSubMtx;
typedef struct {
  u32 type;
  u64 *image;
  u16 tmem;
  u16 tsize;
  u16 tline;
  u16 sid;
  u32 flag;
  u32 mask;
} uObjTxtrBlock_t;
typedef struct {
  u32 type;
  u64 *image;
  u16 tmem;
  u16 twidth;
  u16 theight;
  u16 sid;
  u32 flag;
  u32 mask;
} uObjTxtrTile_t;
typedef struct {
  u32 type;
  u64 *image;
  u16 phead;
  u16 pnum;
  u16 zero;
  u16 sid;
  u32 flag;
  u32 mask;
} uObjTxtrTLUT_t;
typedef union {
  uObjTxtrBlock_t block;
  uObjTxtrTile_t tile;
  uObjTxtrTLUT_t tlut;
  long long int force_structure_alignment;
} uObjTxtr;
typedef struct {
  uObjTxtr txtr;
  uObjSprite sprite;
} uObjTxSprite;
extern u64 gspS2DEX_fifoTextStart[], gspS2DEX_fifoTextEnd[];
extern u64 gspS2DEX_fifoDataStart[], gspS2DEX_fifoDataEnd[];
extern u64 gspS2DEX_fifo_dTextStart[], gspS2DEX_fifo_dTextEnd[];
extern u64 gspS2DEX_fifo_dDataStart[], gspS2DEX_fifo_dDataEnd[];
extern u64 gspS2DEX2_fifoTextStart[], gspS2DEX2_fifoTextEnd[];
extern u64 gspS2DEX2_fifoDataStart[], gspS2DEX2_fifoDataEnd[];
extern u64 gspS2DEX2_xbusTextStart[], gspS2DEX2_xbusTextEnd[];
extern u64 gspS2DEX2_xbusDataStart[], gspS2DEX2_xbusDataEnd[];
extern void guS2DInitBg(uObjBg *);
  extern void guS2D2EmuSetScissor(u32, u32, u32, u32, u8);
  extern void guS2D2EmuBgRect1Cyc(Gfx **, uObjBg *);
typedef struct z_Light_t {
              struct LightInfo* info;
              struct z_Light_t* prev;
              struct z_Light_t* next;
} z_Light;
typedef struct {
              z_Light* lightsHead;
              u8 ambientRed;
              u8 ambientGreen;
              u8 ambientBlue;
              u8 unk_07;
              u8 unk_08;
              u8 unk_09;
              s16 unk_0A;
              s16 unk_0C;
} LightingContext;
typedef struct {
                int numOccupied;
                int nextFree;
                z_Light lights[32];
} LightsList;
typedef struct {
              u8 type;
              u16 params[6];
} LightInfo;
typedef struct {
              s8 dirX;
              s8 dirY;
              s8 dirZ;
              u8 red;
              u8 green;
              u8 blue;
              u16 pad[3];
} LightInfoDirectionalParams;
typedef struct {
              s16 posX;
              s16 posY;
              s16 posZ;
              u8 red;
              u8 green;
              u8 blue;
              u8 unk_09;
              s16 radius;
} LightInfoPositionalParams;
typedef struct {
               u8 numLights;
               u8 enablePosLights;
               s8 pad2[6];
               Ambient ambient;
               Light lights[7];
} LightMapper;
typedef struct {
              u8 type;
              LightInfoDirectionalParams params;
} LightInfoDirectional;
typedef struct {
              u8 type;
              LightInfoPositionalParams params;
} LightInfoPositional;
typedef struct {
               u32 vromAddr;
               void* dramAddr;
               u32 size;
               char* filename;
               s32 line;
               s32 unk_14;
               OSMesgQueue* notifyQueue;
               OSMesg notifyMsg;
} DmaRequest;
typedef struct {
               u32 vromStart;
               u32 vromEnd;
               u32 romStart;
               u32 romEnd;
} DmaEntry;
typedef struct {
    f32 x, y;
} Vec2f;
typedef struct {
    f32 x, y, z;
} Vec3f;
typedef struct {
    s16 x, y, z;
} Vec3s;
typedef struct {
    s32 x, y, z;
} Vec3i;
struct GlobalContext;
struct Actor;
typedef struct SkelAnime SkelAnime;
typedef struct {
                Vec3s translation;
                u8 firstChildIndex;
                u8 nextLimbIndex;
                Gfx* displayLists[1];
} SkelLimbEntry;
typedef struct {
                SkelLimbEntry* limbs[1];
} Skeleton;
typedef struct {
                Skeleton* skeletonSeg;
                u8 limbCount;
                char unk_05[3];
                u8 dListCount;
} SkeletonHeader;
typedef s16 AnimationRotationValue;
typedef struct {
                u16 x;
                u16 y;
                u16 z;
} AnimationRotationIndex;
typedef struct {
    s16 frameCount;
    s16 unk_02;
} GenericAnimationHeader;
typedef struct {
                GenericAnimationHeader genericHeader;
                u32 rotationValueSeg;
                u32 rotationIndexSeg;
                u16 limit;
} AnimationHeader;
typedef enum {
    ANIMATION_LINKANIMETION,
    ANIMATION_TYPE1,
    ANIMATION_TYPE2,
    ANIMATION_TYPE3,
    ANIMATION_TYPE4,
    ANIMATION_TYPE5
} AnimationType;
typedef struct {
                DmaRequest req;
                OSMesgQueue msgQueue;
                OSMesg msg;
} AnimationEntryType0;
typedef struct {
                u8 unk_00;
                u8 vecCount;
                Vec3s* dst;
                Vec3s* src;
} AnimationEntryType1;
typedef struct {
                u8 unk_00;
                u8 limbCount;
                Vec3s* unk_04;
                Vec3s* unk_08;
                f32 unk_0C;
} AnimationEntryType2;
typedef struct {
                u8 unk_00;
                u8 vecCount;
                Vec3s* dst;
                Vec3s* src;
                u8* index;
} AnimationEntryType3;
typedef struct {
                u8 unk_00;
                u8 vecCount;
                char unk_02[0x2];
                Vec3s* dst;
                Vec3s* src;
                u8* index;
} AnimationEntryType4;
typedef struct {
                struct Actor* actor;
                SkelAnime* skelAnime;
                f32 unk_08;
} AnimationEntryType5;
typedef struct {
                u8 raw[0x3C];
} AnimationEntryRaw;
typedef union {
    AnimationEntryRaw raw;
    AnimationEntryType0 type0;
    AnimationEntryType1 type1;
    AnimationEntryType2 type2;
    AnimationEntryType3 type3;
    AnimationEntryType4 type4;
    AnimationEntryType5 type5;
} AnimationEntryType;
typedef struct {
                u8 type;
                u8 unk_01;
                AnimationEntryType types;
} AnimationEntry;
typedef struct AnimationContext {
    s16 animationCount;
    char unk_02[2];
    AnimationEntry entries[50];
} AnimationContext;
typedef struct {
    GenericAnimationHeader genericHeader;
    u32 animationSegAddress;
} LinkAnimetionEntry;
struct SkelAnime {
               u8 limbCount;
               u8 mode;
               u8 dListCount;
               s8 unk_03;
               Skeleton* skeleton;
    union {
        AnimationHeader* animCurrentSeg;
        LinkAnimetionEntry* linkAnimetionSeg;
        GenericAnimationHeader* genericSeg;
    };
               f32 initialFrame;
               f32 animFrameCount;
               f32 totalFrames;
               f32 animCurrentFrame;
               f32 animPlaybackSpeed;
               Vec3s* actorDrawTbl;
               Vec3s* transitionDrawTbl;
               f32 transCurrentFrame;
               f32 transitionStep;
               s32 (*animUpdate)();
               s8 initFlags;
               u8 flags;
               s16 prevFrameRot;
               Vec3s prevFramePos;
               Vec3s unk_3E;
};
typedef s32 (*SkelAnime_LimbUpdateMatrix)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList,
             Vec3f* pos, Vec3s* rot, struct Actor* actor);
typedef void (*SkelAnime_LimbAppendDlist)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList,
                                          Vec3s* rot, struct Actor* actor);
typedef s32 (*SkelAnime_LimbUpdateMatrix2)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList,
             Vec3f* pos, Vec3s* rot, struct Actor* actor, Gfx** gfx);
typedef void (*SkelAnime_LimbAppendDlist2)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList,
                                          Vec3s* rot, struct Actor* actor, Gfx** gfx);
typedef void (*AnimationEntryCallback)(struct GlobalContext*, AnimationEntryType*);
extern u32 link_animetion_segment;
struct Actor;
struct GlobalContext;
struct LightMapper;
typedef struct {
    Vec3f pos;
    Vec3s rot;
} PosRot;
typedef struct {
               char unk_00[0x8];
               Vec3s norm;
               s16 dist;
} CollisionPoly;
typedef void (*ActorFunc)(struct Actor*, struct GlobalContext*);
typedef struct {
               s16 id;
               u8 type;
               u8 room;
               u32 flags;
               s16 objectId;
               u32 instanceSize;
               ActorFunc init;
               ActorFunc destroy;
               ActorFunc update;
               ActorFunc draw;
} ActorInit;
typedef enum {
    ALLOCTYPE_NORMAL,
    ALLOCTYPE_ABSOLUTE,
    ALLOCTYPE_PERMANENT
} AllocType;
typedef struct {
               u32 vromStart;
               u32 vromEnd;
               void* vramStart;
               void* vramEnd;
               void* loadedRamAddr;
               ActorInit* initInfo;
               char* name;
               u16 allocType;
               s8 nbLoaded;
} ActorOverlay;
typedef struct {
    struct {
        char damage : 4;
        char effect : 4;
    } attack[32];
} ActorDamageChart;
typedef struct {
               ActorDamageChart* damageChart;
               Vec3f displacement;
               s16 unk_10;
               s16 unk_12;
               u16 unk_14;
               u8 mass;
               u8 health;
               u8 damage;
               u8 damageEffect;
               u8 impactEffect;
               u8 unk_1B;
} SubActorStruct98;
typedef struct {
               Vec3s rot;
               u8 unk_06;
               f32 unk_08;
               void (*shadowDrawFunc)(struct Actor*, struct LightMapper*, struct GlobalContext*);
               f32 unk_10;
               u8 unk_14;
               u8 unk_15;
} ActorShape;
typedef struct Actor {
                s16 id;
                u8 type;
                s8 room;
                u32 flags;
                PosRot initPosRot;
                s16 params;
                s8 objBankIndex;
                s8 unk_1F;
                u16 soundEffect;
                u16 unk_22;
                PosRot posRot;
                PosRot posRot2;
                f32 unk_4C;
                Vec3f scale;
                Vec3f velocity;
                f32 speedXZ;
                f32 gravity;
                f32 minVelocityY;
                CollisionPoly* wallPoly;
                CollisionPoly* floorPoly;
                u8 wallPolySource;
                u8 floorPolySource;
                s16 unk_7E;
                f32 unk_80;
                f32 unk_84;
                u16 bgCheckFlags;
                s16 rotTowardsLinkY;
                f32 waterSurfaceDist;
                f32 xzDistanceFromLink;
                f32 yDistanceFromLink;
                SubActorStruct98 sub_98;
                ActorShape shape;
                Vec3f unk_CC[2];
                Vec3f unk_E4;
                f32 unk_F0;
                f32 unk_F4;
                f32 unk_F8;
                f32 unk_FC;
                Vec3f pos4;
                u8 unk_10C;
                u8 unk_10D;
                u16 textId;
                u16 freeze;
                u16 unk_112;
                u8 unk_114;
                u8 activelyDrawn;
                u8 unk_116;
                u8 naviEnemyId;
                struct Actor* attachedA;
                struct Actor* attachedB;
                struct Actor* prev;
                struct Actor* next;
                ActorFunc init;
                ActorFunc destroy;
                ActorFunc update;
                ActorFunc draw;
                ActorOverlay* overlayEntry;
                char dbgPad[0x10];
} Actor;
typedef struct {
               u8 health;
               s16 unk_02;
               s16 unk_04;
               u8 mass;
} Sub98Init4;
typedef struct {
               u8 health;
               s16 unk_10;
               s16 unk_12;
               u16 unk_14;
               u8 mass;
} Sub98Init5;
typedef enum {
    COLTYPE_CYLINDER = 1,
    COLTYPE_CYLINDER_GROUP = 0,
    COLTYPE_QUAD = 3,
    COLTYPE_TRIANGLE_GROUP = 2
} ColliderType;
typedef struct {
               Actor* actor;
               Actor* at;
               Actor* ac;
               Actor* ot;
               u8 colliderFlags;
               u8 collideFlags;
               u8 maskA;
               u8 maskB;
               u8 unk_14;
               u8 type;
} Collider;
typedef struct {
               s32 flags;
               u8 unk_04;
               u8 damage;
} ColliderTouch;
typedef struct {
               s32 flags;
               u8 effect;
               u8 unk_05;
               s16 unk_06;
               s16 unk_08;
               s16 unk_0A;
} ColliderBump;
typedef struct ColliderBody {
               ColliderTouch toucher;
               ColliderBump bumper;
               u8 flags;
               u8 toucherFlags;
               u8 bumperFlags;
               u8 flags2;
               s32 unk_18;
               struct ColliderBodyEntry* colBuf;
               s32 unk_20;
               struct ColliderBody* colliding;
} ColliderBody;
typedef struct ColliderBodyEntry {
               ColliderBody c;
               char unk_28[0x18];
} ColliderBodyEntry;
typedef struct {
               u8 bodyFlags;
               u8 unk_09[0x3];
               s32 toucherMask;
               u8 bumperEffect;
               u8 toucherDamage;
               u8 unk_12[0x2];
               s32 bumperMask;
               u8 unk_18[0x4];
               u8 toucherFlags;
               u8 bumperFlags;
               u8 bodyFlags2;
               u8 unk_1F;
} ColliderBodyInfoInner;
typedef struct {
               u8 unk_00;
               u8 colliderFlags;
               u8 collideFlags;
               u8 maskA;
               u8 maskB;
               u8 type;
               u8 unk_06[0x2];
} ColliderBodyInfo;
typedef struct {
               s16 radius;
               s16 height;
               s16 yShift;
               Vec3s position;
} ColliderDimensions;
typedef struct {
               Collider base;
               ColliderBody body;
               ColliderDimensions dim;
} ColliderCylinderMain;
typedef struct {
               ColliderBodyInfo body;
               ColliderBodyInfoInner inner;
               ColliderDimensions dim;
} ColliderCylinderInit;
typedef struct {
               Actor* actor;
               char unk_04[0x10];
               Vec3f scale1;
               Vec3s rot1;
               Vec3f pos1;
               Vec3f scale2;
               Vec3s rot2;
               Vec3f pos2;
               char unk_54[0x10];
} ActorMesh;
typedef struct {
                Actor actor;
                u32 dynaPolyId;
                f32 unk_150;
                f32 unk_154;
                s16 unk_158;
                u16 unk_15A;
                u32 unk_15C;
                u8 unk_160;
                s16 unk_162;
} DynaPolyActor;
typedef struct {
                 Actor actor;
                 s8 currentTunic;
                 s8 currentSword;
                 s8 currentShield;
                 s8 currentBoots;
                 s8 unk_150;
                 s8 unk_151;
                 s8 unk_152;
                 s8 unk_153;
                 s8 unk_154;
                 char unk_155[0x008];
                 u8 unk_15D;
                 u8 unk_15E;
                 u8 currentMask;
                 char unk_160[0x050];
                 u32 unk_1B0;
                 SkelAnime skelAnime;
                 char unk_1F8[0x1B4];
                 Actor* heldActor;
                 char unk_3B0[0x084];
                 u8 getItemId;
                 u16 getItemDirection;
                 Actor* interactRangeActor;
                 s8 unk_43C;
                 Actor* rideActor;
                 u8 action;
                 char unk_445[0x003];
                 Actor* unk_448;
                 char unk_44C[0x01E];
                 u16 unk_46A;
                 char unk_46C[0x6E];
                 s16 unk_4DA;
                 char unk_4DC[0x188];
                 Actor* unk_664;
                 char unk_668[0x004];
                 s32 unk_66C;
                 char unk_670[0x00C];
                 u32 stateFlags1;
                 u32 stateFlags2;
                 char unk_684[0x008];
                 Actor* unk_68C;
                 char unk_690[0x002];
                 u8 unk_692;
                 s8 exchangeItemId;
                 Actor* unk_694;
                 f32 unk_698;
                 char unk_69C[0x008];
                 f32 unk_6A4;
                 char unk_6A8[0x5];
                 u8 unk_6AD;
                 char unk_6AE[0x1A];
                 SkelAnime skelAnime2;
                 char unk_70C[0x128];
                 s16 unk_834;
                 char unk_836[0x006];
                 s16 unk_83C;
                 char unk_83E[0x004];
                 s8 swordAnimation;
                 s8 swordState;
                 u8 unk_844;
                 u8 unk_845;
                 u8 unk_846;
                 char unk_847[0x004];
                 s8 unk_84B[1];
                 char unk_84C[0x003];
                 s8 unk_84F;
                 char unk_850[0x050];
                 u8 unk_8A0;
                 u8 unk_8A1;
                 u16 unk_8A2;
                 f32 unk_8A4;
                 f32 unk_8A8;
                 char unk_8AC[0x174];
                 MtxF mf_A20;
                 char unk_A60[0x18];
                 s8 unk_A78;
                 char unk_A79[0x1B];
} Player;
typedef enum {
               ACTORTYPE_SWITCH,
               ACTORTYPE_BG,
               ACTORTYPE_PLAYER,
               ACTORTYPE_EXPLOSIVES,
               ACTORTYPE_NPC,
               ACTORTYPE_ENEMY,
               ACTORTYPE_PROP,
               ACTORTYPE_ITEMACTION,
               ACTORTYPE_MISC,
               ACTORTYPE_BOSS,
               ACTORTYPE_DOOR,
               ACTORTYPE_CHEST
} ActorType;
typedef enum {
                 ACTOR_PLAYER,
                 ACTOR_UNSET_1,
                 ACTOR_EN_TEST,
                 ACTOR_UNSET_3,
                 ACTOR_EN_GIRLA,
                 ACTOR_UNSET_5,
                 ACTOR_UNSET_6,
                 ACTOR_EN_PART,
                 ACTOR_EN_LIGHT,
                 ACTOR_EN_DOOR,
                 ACTOR_EN_BOX,
                 ACTOR_BG_DY_YOSEIZO,
                 ACTOR_BG_HIDAN_FIREWALL,
                 ACTOR_EN_POH,
                 ACTOR_EN_OKUTA,
                 ACTOR_BG_YDAN_SP,
                 ACTOR_EN_BOM,
                 ACTOR_EN_WALLMAS,
                 ACTOR_EN_DODONGO,
                 ACTOR_EN_FIREFLY,
                 ACTOR_EN_HORSE,
                 ACTOR_EN_ITEM00,
                 ACTOR_EN_ARROW,
                 ACTOR_UNSET_17,
                 ACTOR_EN_ELF,
                 ACTOR_EN_NIW,
                 ACTOR_UNSET_1A,
                 ACTOR_EN_TITE,
                 ACTOR_EN_REEBA,
                 ACTOR_EN_PEEHAT,
                 ACTOR_EN_BUTTE,
                 ACTOR_UNSET_1F,
                 ACTOR_EN_INSECT,
                 ACTOR_EN_FISH,
                 ACTOR_UNSET_22,
                 ACTOR_EN_HOLL,
                 ACTOR_EN_SCENE_CHANGE,
                 ACTOR_EN_ZF,
                 ACTOR_EN_HATA,
                 ACTOR_BOSS_DODONGO,
                 ACTOR_BOSS_GOMA,
                 ACTOR_EN_ZL1,
                 ACTOR_EN_VIEWER,
                 ACTOR_EN_GOMA,
                 ACTOR_BG_PUSHBOX,
                 ACTOR_EN_BUBBLE,
                 ACTOR_DOOR_SHUTTER,
                 ACTOR_EN_DODOJR,
                 ACTOR_EN_BDFIRE,
                 ACTOR_UNSET_31,
                 ACTOR_EN_BOOM,
                 ACTOR_EN_TORCH2,
                 ACTOR_EN_BILI,
                 ACTOR_EN_TP,
                 ACTOR_UNSET_36,
                 ACTOR_EN_ST,
                 ACTOR_EN_BW,
                 ACTOR_EN_A_OBJ,
                 ACTOR_EN_EIYER,
                 ACTOR_EN_RIVER_SOUND,
                 ACTOR_EN_HORSE_NORMAL,
                 ACTOR_EN_OSSAN,
                 ACTOR_BG_TREEMOUTH,
                 ACTOR_BG_DODOAGO,
                 ACTOR_BG_HIDAN_DALM,
                 ACTOR_BG_HIDAN_HROCK,
                 ACTOR_EN_HORSE_GANON,
                 ACTOR_BG_HIDAN_ROCK,
                 ACTOR_BG_HIDAN_RSEKIZOU,
                 ACTOR_BG_HIDAN_SEKIZOU,
                 ACTOR_BG_HIDAN_SIMA,
                 ACTOR_BG_HIDAN_SYOKU,
                 ACTOR_EN_XC,
                 ACTOR_BG_HIDAN_CURTAIN,
                 ACTOR_BG_SPOT00_HANEBASI,
                 ACTOR_EN_MB,
                 ACTOR_EN_BOMBF,
                 ACTOR_EN_ZL2,
                 ACTOR_BG_HIDAN_FSLIFT,
                 ACTOR_EN_OE2,
                 ACTOR_BG_YDAN_HASI,
                 ACTOR_BG_YDAN_MARUTA,
                 ACTOR_BOSS_GANONDROF,
                 ACTOR_UNSET_53,
                 ACTOR_EN_AM,
                 ACTOR_EN_DEKUBABA,
                 ACTOR_EN_M_FIRE1,
                 ACTOR_EN_M_THUNDER,
                 ACTOR_BG_DDAN_JD,
                 ACTOR_BG_BREAKWALL,
                 ACTOR_EN_JJ,
                 ACTOR_EN_HORSE_ZELDA,
                 ACTOR_BG_DDAN_KD,
                 ACTOR_DOOR_WARP1,
                 ACTOR_OBJ_SYOKUDAI,
                 ACTOR_ITEM_B_HEART,
                 ACTOR_EN_DEKUNUTS,
                 ACTOR_BG_MENKURI_KAITEN,
                 ACTOR_BG_MENKURI_EYE,
                 ACTOR_EN_VALI,
                 ACTOR_BG_MIZU_MOVEBG,
                 ACTOR_BG_MIZU_WATER,
                 ACTOR_ARMS_HOOK,
                 ACTOR_EN_FHG,
                 ACTOR_BG_MORI_HINERI,
                 ACTOR_EN_BB,
                 ACTOR_BG_TOKI_HIKARI,
                 ACTOR_EN_YUKABYUN,
                 ACTOR_BG_TOKI_SWD,
                 ACTOR_EN_FHG_FIRE,
                 ACTOR_BG_MJIN,
                 ACTOR_BG_HIDAN_KOUSI,
                 ACTOR_DOOR_TOKI,
                 ACTOR_BG_HIDAN_HAMSTEP,
                 ACTOR_EN_BIRD,
                 ACTOR_UNSET_73,
                 ACTOR_UNSET_74,
                 ACTOR_UNSET_75,
                 ACTOR_UNSET_76,
                 ACTOR_EN_WOOD02,
                 ACTOR_UNSET_78,
                 ACTOR_UNSET_79,
                 ACTOR_UNSET_7A,
                 ACTOR_UNSET_7B,
                 ACTOR_EN_LIGHTBOX,
                 ACTOR_EN_PU_BOX,
                 ACTOR_UNSET_7E,
                 ACTOR_UNSET_7F,
                 ACTOR_EN_TRAP,
                 ACTOR_EN_AROW_TRAP,
                 ACTOR_EN_VASE,
                 ACTOR_UNSET_83,
                 ACTOR_EN_TA,
                 ACTOR_EN_TK,
                 ACTOR_BG_MORI_BIGST,
                 ACTOR_BG_MORI_ELEVATOR,
                 ACTOR_BG_MORI_KAITENKABE,
                 ACTOR_BG_MORI_RAKKATENJO,
                 ACTOR_EN_VM,
                 ACTOR_DEMO_EFFECT,
                 ACTOR_DEMO_KANKYO,
                 ACTOR_BG_HIDAN_FWBIG,
                 ACTOR_EN_FLOORMAS,
                 ACTOR_EN_HEISHI1,
                 ACTOR_EN_RD,
                 ACTOR_EN_PO_SISTERS,
                 ACTOR_BG_HEAVY_BLOCK,
                 ACTOR_BG_PO_EVENT,
                 ACTOR_OBJ_MURE,
                 ACTOR_EN_SW,
                 ACTOR_BOSS_FD,
                 ACTOR_OBJECT_KANKYO,
                 ACTOR_EN_DU,
                 ACTOR_EN_FD,
                 ACTOR_EN_HORSE_LINK_CHILD,
                 ACTOR_DOOR_ANA,
                 ACTOR_BG_SPOT02_OBJECTS,
                 ACTOR_BG_HAKA,
                 ACTOR_MAGIC_WIND,
                 ACTOR_MAGIC_FIRE,
                 ACTOR_UNSET_A0,
                 ACTOR_EN_RU1,
                 ACTOR_BOSS_FD2,
                 ACTOR_EN_FD_FIRE,
                 ACTOR_EN_DH,
                 ACTOR_EN_DHA,
                 ACTOR_EN_RL,
                 ACTOR_EN_ENCOUNT1,
                 ACTOR_DEMO_DU,
                 ACTOR_DEMO_IM,
                 ACTOR_DEMO_TRE_LGT,
                 ACTOR_EN_FW,
                 ACTOR_BG_VB_SIMA,
                 ACTOR_EN_VB_BALL,
                 ACTOR_BG_HAKA_MEGANE,
                 ACTOR_BG_HAKA_MEGANEBG,
                 ACTOR_BG_HAKA_SHIP,
                 ACTOR_BG_HAKA_SGAMI,
                 ACTOR_UNSET_B2,
                 ACTOR_EN_HEISHI2,
                 ACTOR_EN_ENCOUNT2,
                 ACTOR_EN_FIRE_ROCK,
                 ACTOR_EN_BROB,
                 ACTOR_MIR_RAY,
                 ACTOR_BG_SPOT09_OBJ,
                 ACTOR_BG_SPOT18_OBJ,
                 ACTOR_BOSS_VA,
                 ACTOR_BG_HAKA_TUBO,
                 ACTOR_BG_HAKA_TRAP,
                 ACTOR_BG_HAKA_HUTA,
                 ACTOR_BG_HAKA_ZOU,
                 ACTOR_BG_SPOT17_FUNEN,
                 ACTOR_EN_SYATEKI_ITM,
                 ACTOR_EN_SYATEKI_MAN,
                 ACTOR_EN_TANA,
                 ACTOR_EN_NB,
                 ACTOR_BOSS_MO,
                 ACTOR_EN_SB,
                 ACTOR_EN_BIGOKUTA,
                 ACTOR_EN_KAREBABA,
                 ACTOR_BG_BDAN_OBJECTS,
                 ACTOR_DEMO_SA,
                 ACTOR_DEMO_GO,
                 ACTOR_EN_IN,
                 ACTOR_EN_TR,
                 ACTOR_BG_SPOT16_BOMBSTONE,
                 ACTOR_UNSET_CE,
                 ACTOR_BG_HIDAN_KOWARERUKABE,
                 ACTOR_BG_BOMBWALL,
                 ACTOR_BG_SPOT08_ICEBLOCK,
                 ACTOR_EN_RU2,
                 ACTOR_OBJ_DEKUJR,
                 ACTOR_BG_MIZU_UZU,
                 ACTOR_BG_SPOT06_OBJECTS,
                 ACTOR_BG_ICE_OBJECTS,
                 ACTOR_BG_HAKA_WATER,
                 ACTOR_UNSET_D8,
                 ACTOR_EN_MA2,
                 ACTOR_EN_BOM_CHU,
                 ACTOR_EN_HORSE_GAME_CHECK,
                 ACTOR_BOSS_TW,
                 ACTOR_EN_RR,
                 ACTOR_EN_BA,
                 ACTOR_EN_BX,
                 ACTOR_EN_ANUBICE,
                 ACTOR_EN_ANUBICE_FIRE,
                 ACTOR_BG_MORI_HASHIGO,
                 ACTOR_BG_MORI_HASHIRA4,
                 ACTOR_BG_MORI_IDOMIZU,
                 ACTOR_BG_SPOT16_DOUGHNUT,
                 ACTOR_BG_BDAN_SWITCH,
                 ACTOR_EN_MA1,
                 ACTOR_BOSS_GANON,
                 ACTOR_BOSS_SST,
                 ACTOR_UNSET_EA,
                 ACTOR_UNSET_EB,
                 ACTOR_EN_NY,
                 ACTOR_EN_FR,
                 ACTOR_ITEM_SHIELD,
                 ACTOR_BG_ICE_SHELTER,
                 ACTOR_EN_ICE_HONO,
                 ACTOR_ITEM_OCARINA,
                 ACTOR_UNSET_F2,
                 ACTOR_UNSET_F3,
                 ACTOR_MAGIC_DARK,
                 ACTOR_DEMO_6K,
                 ACTOR_EN_ANUBICE_TAG,
                 ACTOR_BG_HAKA_GATE,
                 ACTOR_BG_SPOT15_SAKU,
                 ACTOR_BG_JYA_GOROIWA,
                 ACTOR_BG_JYA_ZURERUKABE,
                 ACTOR_UNSET_FB,
                 ACTOR_BG_JYA_COBRA,
                 ACTOR_BG_JYA_KANAAMI,
                 ACTOR_FISHING,
                 ACTOR_OBJ_OSHIHIKI,
                 ACTOR_BG_GATE_SHUTTER,
                 ACTOR_EFF_DUST,
                 ACTOR_BG_SPOT01_FUSYA,
                 ACTOR_BG_SPOT01_IDOHASHIRA,
                 ACTOR_BG_SPOT01_IDOMIZU,
                 ACTOR_BG_PO_SYOKUDAI,
                 ACTOR_BG_GANON_OTYUKA,
                 ACTOR_BG_SPOT15_RRBOX,
                 ACTOR_BG_UMAJUMP,
                 ACTOR_UNSET_109,
                 ACTOR_ARROW_FIRE,
                 ACTOR_ARROW_ICE,
                 ACTOR_ARROW_LIGHT,
                 ACTOR_UNSET_10D,
                 ACTOR_UNSET_10E,
                 ACTOR_ITEM_ETCETERA,
                 ACTOR_OBJ_KIBAKO,
                 ACTOR_OBJ_TSUBO,
                 ACTOR_EN_WONDER_ITEM,
                 ACTOR_EN_IK,
                 ACTOR_DEMO_IK,
                 ACTOR_EN_SKJ,
                 ACTOR_EN_SKJNEEDLE,
                 ACTOR_EN_G_SWITCH,
                 ACTOR_DEMO_EXT,
                 ACTOR_DEMO_SHD,
                 ACTOR_EN_DNS,
                 ACTOR_ELF_MSG,
                 ACTOR_EN_HONOTRAP,
                 ACTOR_EN_TUBO_TRAP,
                 ACTOR_OBJ_ICE_POLY,
                 ACTOR_BG_SPOT03_TAKI,
                 ACTOR_BG_SPOT07_TAKI,
                 ACTOR_EN_FZ,
                 ACTOR_EN_PO_RELAY,
                 ACTOR_BG_RELAY_OBJECTS,
                 ACTOR_EN_DIVING_GAME,
                 ACTOR_EN_KUSA,
                 ACTOR_OBJ_BEAN,
                 ACTOR_OBJ_BOMBIWA,
                 ACTOR_UNSET_128,
                 ACTOR_UNSET_129,
                 ACTOR_OBJ_SWITCH,
                 ACTOR_OBJ_ELEVATOR,
                 ACTOR_OBJ_LIFT,
                 ACTOR_OBJ_HSBLOCK,
                 ACTOR_EN_OKARINA_TAG,
                 ACTOR_EN_YABUSAME_MARK,
                 ACTOR_EN_GOROIWA,
                 ACTOR_EN_EX_RUPPY,
                 ACTOR_EN_TORYO,
                 ACTOR_EN_DAIKU,
                 ACTOR_UNSET_134,
                 ACTOR_EN_NWC,
                 ACTOR_EN_BLKOBJ,
                 ACTOR_ITEM_INBOX,
                 ACTOR_EN_GE1,
                 ACTOR_OBJ_BLOCKSTOP,
                 ACTOR_EN_SDA,
                 ACTOR_EN_CLEAR_TAG,
                 ACTOR_EN_NIW_LADY,
                 ACTOR_EN_GM,
                 ACTOR_EN_MS,
                 ACTOR_EN_HS,
                 ACTOR_BG_INGATE,
                 ACTOR_EN_KANBAN,
                 ACTOR_EN_HEISHI3,
                 ACTOR_EN_SYATEKI_NIW,
                 ACTOR_EN_ATTACK_NIW,
                 ACTOR_BG_SPOT01_IDOSOKO,
                 ACTOR_EN_SA,
                 ACTOR_EN_WONDER_TALK,
                 ACTOR_BG_GJYO_BRIDGE,
                 ACTOR_EN_DS,
                 ACTOR_EN_MK,
                 ACTOR_EN_BOM_BOWL_MAN,
                 ACTOR_EN_BOM_BOWL_PIT,
                 ACTOR_EN_OWL,
                 ACTOR_EN_ISHI,
                 ACTOR_OBJ_HANA,
                 ACTOR_OBJ_LIGHTSWITCH,
                 ACTOR_OBJ_MURE2,
                 ACTOR_EN_GO,
                 ACTOR_EN_FU,
                 ACTOR_UNSET_154,
                 ACTOR_EN_CHANGER,
                 ACTOR_BG_JYA_MEGAMI,
                 ACTOR_BG_JYA_LIFT,
                 ACTOR_BG_JYA_BIGMIRROR,
                 ACTOR_BG_JYA_BOMBCHUIWA,
                 ACTOR_BG_JYA_AMISHUTTER,
                 ACTOR_BG_JYA_BOMBIWA,
                 ACTOR_BG_SPOT18_BASKET,
                 ACTOR_UNSET_15D,
                 ACTOR_EN_GANON_ORGAN,
                 ACTOR_EN_SIOFUKI,
                 ACTOR_EN_STREAM,
                 ACTOR_UNSET_161,
                 ACTOR_EN_MM,
                 ACTOR_EN_KO,
                 ACTOR_EN_KZ,
                 ACTOR_EN_WEATHER_TAG,
                 ACTOR_BG_SST_FLOOR,
                 ACTOR_EN_ANI,
                 ACTOR_EN_EX_ITEM,
                 ACTOR_BG_JYA_IRONOBJ,
                 ACTOR_EN_JS,
                 ACTOR_EN_JSJUTAN,
                 ACTOR_EN_CS,
                 ACTOR_EN_MD,
                 ACTOR_EN_HY,
                 ACTOR_EN_GANON_MANT,
                 ACTOR_EN_OKARINA_EFFECT,
                 ACTOR_EN_MAG,
                 ACTOR_DOOR_GERUDO,
                 ACTOR_ELF_MSG2,
                 ACTOR_DEMO_GT,
                 ACTOR_EN_PO_FIELD,
                 ACTOR_EFC_ERUPC,
                 ACTOR_BG_ZG,
                 ACTOR_EN_HEISHI4,
                 ACTOR_EN_ZL3,
                 ACTOR_BOSS_GANON2,
                 ACTOR_EN_KAKASI,
                 ACTOR_EN_TAKARA_MAN,
                 ACTOR_OBJ_MAKEOSHIHIKI,
                 ACTOR_OCEFF_SPOT,
                 ACTOR_END_TITLE,
                 ACTOR_UNSET_180,
                 ACTOR_EN_TORCH,
                 ACTOR_DEMO_EC,
                 ACTOR_SHOT_SUN,
                 ACTOR_EN_DY_EXTRA,
                 ACTOR_EN_WONDER_TALK2,
                 ACTOR_EN_GE2,
                 ACTOR_OBJ_ROOMTIMER,
                 ACTOR_EN_SSH,
                 ACTOR_EN_STH,
                 ACTOR_OCEFF_WIPE,
                 ACTOR_OCEFF_STORM,
                 ACTOR_EN_WEIYER,
                 ACTOR_BG_SPOT05_SOKO,
                 ACTOR_BG_JYA_1FLIFT,
                 ACTOR_BG_JYA_HAHENIRON,
                 ACTOR_BG_SPOT12_GATE,
                 ACTOR_BG_SPOT12_SAKU,
                 ACTOR_EN_HINTNUTS,
                 ACTOR_EN_NUTSBALL,
                 ACTOR_BG_SPOT00_BREAK,
                 ACTOR_EN_SHOPNUTS,
                 ACTOR_EN_IT,
                 ACTOR_EN_GELDB,
                 ACTOR_OCEFF_WIPE2,
                 ACTOR_OCEFF_WIPE3,
                 ACTOR_EN_NIW_GIRL,
                 ACTOR_EN_DOG,
                 ACTOR_EN_SI,
                 ACTOR_BG_SPOT01_OBJECTS2,
                 ACTOR_OBJ_COMB,
                 ACTOR_BG_SPOT11_BAKUDANKABE,
                 ACTOR_OBJ_KIBAKO2,
                 ACTOR_EN_DNT_DEMO,
                 ACTOR_EN_DNT_JIJI,
                 ACTOR_EN_DNT_NOMAL,
                 ACTOR_EN_GUEST,
                 ACTOR_BG_BOM_GUARD,
                 ACTOR_EN_HS2,
                 ACTOR_DEMO_KEKKAI,
                 ACTOR_BG_SPOT08_BAKUDANKABE,
                 ACTOR_BG_SPOT17_BAKUDANKABE,
                 ACTOR_UNSET_1AA,
                 ACTOR_OBJ_MURE3,
                 ACTOR_EN_TG,
                 ACTOR_EN_MU,
                 ACTOR_EN_GO2,
                 ACTOR_EN_WF,
                 ACTOR_EN_SKB,
                 ACTOR_DEMO_GJ,
                 ACTOR_DEMO_GEFF,
                 ACTOR_BG_GND_FIREMEIRO,
                 ACTOR_BG_GND_DARKMEIRO,
                 ACTOR_BG_GND_SOULMEIRO,
                 ACTOR_BG_GND_NISEKABE,
                 ACTOR_BG_GND_ICEBLOCK,
                 ACTOR_EN_GB,
                 ACTOR_EN_GS,
                 ACTOR_BG_MIZU_BWALL,
                 ACTOR_BG_MIZU_SHUTTER,
                 ACTOR_EN_DAIKU_KAKARIKO,
                 ACTOR_BG_BOWL_WALL,
                 ACTOR_EN_WALL_TUBO,
                 ACTOR_EN_PO_DESERT,
                 ACTOR_EN_CROW,
                 ACTOR_DOOR_KILLER,
                 ACTOR_BG_SPOT11_OASIS,
                 ACTOR_BG_SPOT18_FUTA,
                 ACTOR_BG_SPOT18_SHUTTER,
                 ACTOR_EN_MA3,
                 ACTOR_EN_COW,
                 ACTOR_BG_ICE_TURARA,
                 ACTOR_BG_ICE_SHUTTER,
                 ACTOR_EN_KAKASI2,
                 ACTOR_EN_KAKASI3,
                 ACTOR_OCEFF_WIPE4,
                 ACTOR_EN_EG,
                 ACTOR_BG_MENKURI_NISEKABE,
                 ACTOR_EN_ZO,
                 ACTOR_OBJ_MAKEKINSUTA,
                 ACTOR_EN_GE3,
                 ACTOR_OBJ_TIMEBLOCK,
                 ACTOR_OBJ_HAMISHI,
                 ACTOR_EN_ZL4,
                 ACTOR_EN_MM2,
                 ACTOR_BG_JYA_BLOCK,
                 ACTOR_OBJ_WARP2BLOCK
} ActorID;
typedef enum {
                 OBJECT_UNSET_0,
                 OBJECT_GAMEPLAY_KEEP,
                 OBJECT_GAMEPLAY_FIELD_KEEP,
                 OBJECT_GAMEPLAY_DANGEON_KEEP,
                 OBJECT_UNSET_4,
                 OBJECT_UNSET_5,
                 OBJECT_HUMAN,
                 OBJECT_OKUTA,
                 OBJECT_CROW,
                 OBJECT_POH,
                 OBJECT_DY_OBJ,
                 OBJECT_WALLMASTER,
                 OBJECT_DODONGO,
                 OBJECT_FIREFLY,
                 OBJECT_BOX,
                 OBJECT_FIRE,
                 OBJECT_UNSET_10,
                 OBJECT_UNSET_11,
                 OBJECT_BUBBLE,
                 OBJECT_NIW,
                 OBJECT_LINK_BOY,
                 OBJECT_LINK_CHILD,
                 OBJECT_TITE,
                 OBJECT_REEBA,
                 OBJECT_PEEHAT,
                 OBJECT_KINGDODONGO,
                 OBJECT_HORSE,
                 OBJECT_ZF,
                 OBJECT_GOMA,
                 OBJECT_ZL1,
                 OBJECT_GOL,
                 OBJECT_DODOJR,
                 OBJECT_TORCH2,
                 OBJECT_BL,
                 OBJECT_TP,
                 OBJECT_OA1,
                 OBJECT_ST,
                 OBJECT_BW,
                 OBJECT_EI,
                 OBJECT_HORSE_NORMAL,
                 OBJECT_OB1,
                 OBJECT_O_ANIME,
                 OBJECT_SPOT04_OBJECTS,
                 OBJECT_DDAN_OBJECTS,
                 OBJECT_HIDAN_OBJECTS,
                 OBJECT_HORSE_GANON,
                 OBJECT_OA2,
                 OBJECT_SPOT00_OBJECTS,
                 OBJECT_MB,
                 OBJECT_BOMBF,
                 OBJECT_SK2,
                 OBJECT_OE1,
                 OBJECT_OE_ANIME,
                 OBJECT_OE2,
                 OBJECT_YDAN_OBJECTS,
                 OBJECT_GND,
                 OBJECT_AM,
                 OBJECT_DEKUBABA,
                 OBJECT_UNSET_3A,
                 OBJECT_OA3,
                 OBJECT_OA4,
                 OBJECT_OA5,
                 OBJECT_OA6,
                 OBJECT_OA7,
                 OBJECT_JJ,
                 OBJECT_OA8,
                 OBJECT_OA9,
                 OBJECT_OB2,
                 OBJECT_OB3,
                 OBJECT_OB4,
                 OBJECT_HORSE_ZELDA,
                 OBJECT_OPENING_DEMO1,
                 OBJECT_WARP1,
                 OBJECT_B_HEART,
                 OBJECT_DEKUNUTS,
                 OBJECT_OE3,
                 OBJECT_OE4,
                 OBJECT_MENKURI_OBJECTS,
                 OBJECT_OE5,
                 OBJECT_OE6,
                 OBJECT_OE7,
                 OBJECT_OE8,
                 OBJECT_OE9,
                 OBJECT_OE10,
                 OBJECT_OE11,
                 OBJECT_OE12,
                 OBJECT_VALI,
                 OBJECT_OA10,
                 OBJECT_OA11,
                 OBJECT_MIZU_OBJECTS,
                 OBJECT_FHG,
                 OBJECT_OSSAN,
                 OBJECT_MORI_HINERI1,
                 OBJECT_BB,
                 OBJECT_TOKI_OBJECTS,
                 OBJECT_YUKABYUN,
                 OBJECT_ZL2,
                 OBJECT_MJIN,
                 OBJECT_MJIN_FLASH,
                 OBJECT_MJIN_DARK,
                 OBJECT_MJIN_FLAME,
                 OBJECT_MJIN_ICE,
                 OBJECT_MJIN_SOUL,
                 OBJECT_MJIN_WIND,
                 OBJECT_MJIN_OKA,
                 OBJECT_HAKA_OBJECTS,
                 OBJECT_SPOT06_OBJECTS,
                 OBJECT_ICE_OBJECTS,
                 OBJECT_RELAY_OBJECTS,
                 OBJECT_PO_FIELD,
                 OBJECT_PO_COMPOSER,
                 OBJECT_MORI_HINERI1A,
                 OBJECT_MORI_HINERI2,
                 OBJECT_MORI_HINERI2A,
                 OBJECT_MORI_OBJECTS,
                 OBJECT_MORI_TEX,
                 OBJECT_SPOT08_OBJ,
                 OBJECT_WARP2,
                 OBJECT_HATA,
                 OBJECT_BIRD,
                 OBJECT_UNSET_78,
                 OBJECT_UNSET_79,
                 OBJECT_UNSET_7A,
                 OBJECT_UNSET_7B,
                 OBJECT_WOOD02,
                 OBJECT_UNSET_7D,
                 OBJECT_UNSET_7E,
                 OBJECT_UNSET_7F,
                 OBJECT_UNSET_80,
                 OBJECT_LIGHTBOX,
                 OBJECT_PU_BOX,
                 OBJECT_UNSET_83,
                 OBJECT_UNSET_84,
                 OBJECT_TRAP,
                 OBJECT_VASE,
                 OBJECT_IM,
                 OBJECT_TA,
                 OBJECT_TK,
                 OBJECT_XC,
                 OBJECT_VM,
                 OBJECT_BV,
                 OBJECT_HAKACH_OBJECTS,
                 OBJECT_EFC_CRYSTAL_LIGHT,
                 OBJECT_EFC_FIRE_BALL,
                 OBJECT_EFC_FLASH,
                 OBJECT_EFC_LGT_SHOWER,
                 OBJECT_EFC_STAR_FIELD,
                 OBJECT_GOD_LGT,
                 OBJECT_LIGHT_RING,
                 OBJECT_TRIFORCE_SPOT,
                 OBJECT_BDAN_OBJECTS,
                 OBJECT_SD,
                 OBJECT_RD,
                 OBJECT_PO_SISTERS,
                 OBJECT_HEAVY_OBJECT,
                 OBJECT_GNDD,
                 OBJECT_FD,
                 OBJECT_DU,
                 OBJECT_FW,
                 OBJECT_MEDAL,
                 OBJECT_HORSE_LINK_CHILD,
                 OBJECT_SPOT02_OBJECTS,
                 OBJECT_HAKA,
                 OBJECT_RU1,
                 OBJECT_SYOKUDAI,
                 OBJECT_FD2,
                 OBJECT_DH,
                 OBJECT_RL,
                 OBJECT_EFC_TW,
                 OBJECT_DEMO_TRE_LGT,
                 OBJECT_GI_KEY,
                 OBJECT_MIR_RAY,
                 OBJECT_BROB,
                 OBJECT_GI_JEWEL,
                 OBJECT_SPOT09_OBJ,
                 OBJECT_SPOT18_OBJ,
                 OBJECT_BDOOR,
                 OBJECT_SPOT17_OBJ,
                 OBJECT_SHOP_DUNGEN,
                 OBJECT_NB,
                 OBJECT_MO,
                 OBJECT_SB,
                 OBJECT_GI_MELODY,
                 OBJECT_GI_HEART,
                 OBJECT_GI_COMPASS,
                 OBJECT_GI_BOSSKEY,
                 OBJECT_GI_MEDAL,
                 OBJECT_GI_NUTS,
                 OBJECT_SA,
                 OBJECT_GI_HEARTS,
                 OBJECT_GI_ARROWCASE,
                 OBJECT_GI_BOMBPOUCH,
                 OBJECT_IN,
                 OBJECT_TR,
                 OBJECT_SPOT16_OBJ,
                 OBJECT_OE1S,
                 OBJECT_OE4S,
                 OBJECT_OS_ANIME,
                 OBJECT_GI_BOTTLE,
                 OBJECT_GI_STICK,
                 OBJECT_GI_MAP,
                 OBJECT_OF1D_MAP,
                 OBJECT_RU2,
                 OBJECT_GI_SHIELD_1,
                 OBJECT_DEKUJR,
                 OBJECT_GI_MAGICPOT,
                 OBJECT_GI_BOMB_1,
                 OBJECT_OF1S,
                 OBJECT_MA2,
                 OBJECT_GI_PURSE,
                 OBJECT_HNI,
                 OBJECT_TW,
                 OBJECT_RR,
                 OBJECT_BXA,
                 OBJECT_ANUBICE,
                 OBJECT_GI_GERUDO,
                 OBJECT_GI_ARROW,
                 OBJECT_GI_BOMB_2,
                 OBJECT_GI_EGG,
                 OBJECT_GI_SCALE,
                 OBJECT_GI_SHIELD_2,
                 OBJECT_GI_HOOKSHOT,
                 OBJECT_GI_OCARINA,
                 OBJECT_GI_MILK,
                 OBJECT_MA1,
                 OBJECT_GANON,
                 OBJECT_SST,
                 OBJECT_NY_UNUSED,
                 OBJECT_UNSET_E4,
                 OBJECT_NY,
                 OBJECT_FR,
                 OBJECT_GI_PACHINKO,
                 OBJECT_GI_BOOMERANG,
                 OBJECT_GI_BOW,
                 OBJECT_GI_GLASSES,
                 OBJECT_GI_LIQUID,
                 OBJECT_ANI,
                 OBJECT_DEMO_6K,
                 OBJECT_GI_SHIELD_3,
                 OBJECT_GI_LETTER,
                 OBJECT_SPOT15_OBJ,
                 OBJECT_JYA_OBJ,
                 OBJECT_GI_CLOTHES,
                 OBJECT_GI_BEAN,
                 OBJECT_GI_FISH,
                 OBJECT_GI_SAW,
                 OBJECT_GI_HAMMER,
                 OBJECT_GI_GRASS,
                 OBJECT_GI_LONGSWORD,
                 OBJECT_SPOT01_OBJECTS,
                 OBJECT_MD_UNUSED,
                 OBJECT_MD,
                 OBJECT_KM1,
                 OBJECT_KW1,
                 OBJECT_ZO,
                 OBJECT_KZ,
                 OBJECT_UMAJUMP,
                 OBJECT_MASTERKOKIRI,
                 OBJECT_MASTERKOKIRIHEAD,
                 OBJECT_MASTERGOLON,
                 OBJECT_MASTERZOORA,
                 OBJECT_AOB,
                 OBJECT_IK,
                 OBJECT_AHG,
                 OBJECT_CNE,
                 OBJECT_GI_NIWATORI,
                 OBJECT_SKJ,
                 OBJECT_GI_BOTTLE_LETTER,
                 OBJECT_BJI,
                 OBJECT_BBA,
                 OBJECT_GI_OCARINA_0,
                 OBJECT_DS,
                 OBJECT_ANE,
                 OBJECT_BOJ,
                 OBJECT_SPOT03_OBJECT,
                 OBJECT_SPOT07_OBJECT,
                 OBJECT_FZ,
                 OBJECT_BOB,
                 OBJECT_GE1,
                 OBJECT_YABUSAME_POINT,
                 OBJECT_GI_BOOTS_2,
                 OBJECT_GI_SEED,
                 OBJECT_GND_MAGIC,
                 OBJECT_D_ELEVATOR,
                 OBJECT_D_HSBLOCK,
                 OBJECT_D_LIFT,
                 OBJECT_MAMENOKI,
                 OBJECT_GOROIWA,
                 OBJECT_UNSET_120,
                 OBJECT_TORYO,
                 OBJECT_DAIKU,
                 OBJECT_UNSET_123,
                 OBJECT_NWC,
                 OBJECT_BLKOBJ,
                 OBJECT_GM,
                 OBJECT_MS,
                 OBJECT_HS,
                 OBJECT_INGATE,
                 OBJECT_LIGHTSWITCH,
                 OBJECT_KUSA,
                 OBJECT_TSUBO,
                 OBJECT_GI_GLOVES,
                 OBJECT_GI_COIN,
                 OBJECT_KANBAN,
                 OBJECT_GJYO_OBJECTS,
                 OBJECT_OWL,
                 OBJECT_MK,
                 OBJECT_FU,
                 OBJECT_GI_KI_TAN_MASK,
                 OBJECT_GI_REDEAD_MASK,
                 OBJECT_GI_SKJ_MASK,
                 OBJECT_GI_RABIT_MASK,
                 OBJECT_GI_TRUTH_MASK,
                 OBJECT_GANON_OBJECTS,
                 OBJECT_SIOFUKI,
                 OBJECT_STREAM,
                 OBJECT_MM,
                 OBJECT_FA,
                 OBJECT_OS,
                 OBJECT_GI_EYE_LOTION,
                 OBJECT_GI_POWDER,
                 OBJECT_GI_MUSHROOM,
                 OBJECT_GI_TICKETSTONE,
                 OBJECT_GI_BROKENSWORD,
                 OBJECT_JS,
                 OBJECT_CS,
                 OBJECT_GI_PRESCRIPTION,
                 OBJECT_GI_BRACELET,
                 OBJECT_GI_SOLDOUT,
                 OBJECT_GI_FROG,
                 OBJECT_MAG,
                 OBJECT_DOOR_GERUDO,
                 OBJECT_GT,
                 OBJECT_EFC_ERUPC,
                 OBJECT_ZL2_ANIME1,
                 OBJECT_ZL2_ANIME2,
                 OBJECT_GI_GOLONMASK,
                 OBJECT_GI_ZORAMASK,
                 OBJECT_GI_GERUDOMASK,
                 OBJECT_GANON2,
                 OBJECT_KA,
                 OBJECT_TS,
                 OBJECT_ZG,
                 OBJECT_GI_HOVERBOOTS,
                 OBJECT_GI_M_ARROW,
                 OBJECT_DS2,
                 OBJECT_EC,
                 OBJECT_FISH,
                 OBJECT_GI_SUTARU,
                 OBJECT_GI_GODDESS,
                 OBJECT_SSH,
                 OBJECT_BIGOKUTA,
                 OBJECT_BG,
                 OBJECT_SPOT05_OBJECTS,
                 OBJECT_SPOT12_OBJ,
                 OBJECT_BOMBIWA,
                 OBJECT_HINTNUTS,
                 OBJECT_RS,
                 OBJECT_SPOT00_BREAK,
                 OBJECT_GLA,
                 OBJECT_SHOPNUTS,
                 OBJECT_GELDB,
                 OBJECT_GR,
                 OBJECT_DOG,
                 OBJECT_JYA_IRON,
                 OBJECT_JYA_DOOR,
                 OBJECT_UNSET_16E,
                 OBJECT_SPOT11_OBJ,
                 OBJECT_KIBAKO2,
                 OBJECT_DNS,
                 OBJECT_DNK,
                 OBJECT_GI_FIRE,
                 OBJECT_GI_INSECT,
                 OBJECT_GI_BUTTERFLY,
                 OBJECT_GI_GHOST,
                 OBJECT_GI_SOUL,
                 OBJECT_BOWL,
                 OBJECT_DEMO_KEKKAI,
                 OBJECT_EFC_DOUGHNUT,
                 OBJECT_GI_DEKUPOUCH,
                 OBJECT_GANON_ANIME1,
                 OBJECT_GANON_ANIME2,
                 OBJECT_GANON_ANIME3,
                 OBJECT_GI_RUPY,
                 OBJECT_SPOT01_MATOYA,
                 OBJECT_SPOT01_MATOYAB,
                 OBJECT_MU,
                 OBJECT_WF,
                 OBJECT_SKB,
                 OBJECT_GJ,
                 OBJECT_GEFF,
                 OBJECT_HAKA_DOOR,
                 OBJECT_GS,
                 OBJECT_PS,
                 OBJECT_BWALL,
                 OBJECT_COW,
                 OBJECT_COB,
                 OBJECT_GI_SWORD_1,
                 OBJECT_DOOR_KILLER,
                 OBJECT_OUKE_HAKA,
                 OBJECT_TIMEBLOCK,
                 OBJECT_ZL4
} ObjectID;
typedef struct {
               u16 entrance;
               u8 ageRestriction;
               u8 flag;
               u32 segAddr;
} EntranceCutscene;
typedef struct {
               s8 continueFlag;
               s8 cameraRoll;
               s16 nextPointFrame;
               f32 viewAngle;
               Vec3s pos;
} CutsceneCameraPoint;
typedef struct {
               u16 base;
               u16 startFrame;
               u16 endFrame;
} CsCmdBase;
typedef struct {
               u8 unk_00;
               u8 setting;
               u16 startFrame;
               u16 endFrame;
} CsCmdEnvLighting;
typedef struct {
               u8 unk_00;
               u8 sequence;
               u16 startFrame;
               u16 endFrame;
} CsCmdMusicChange;
typedef struct {
               u16 type;
               u16 startFrame;
               u16 endFrame;
} CsCmdMusicFade;
typedef struct {
               u16 unk_00;
               u16 startFrame;
               u16 endFrame;
               u8 unk_06;
               u8 unk_07;
               u8 unk_08;
} CsCmdUnknown9;
typedef struct {
               u16 unk_00;
               u16 startFrame;
               u16 endFrame;
               u8 hour;
               u8 minute;
} CsCmdDayTime;
typedef struct {
               u16 base;
               u16 startFrame;
               u16 endFrame;
               u16 type;
               u16 textId1;
               u16 textId2;
} CsCmdTextbox;
typedef struct {
               u16 action;
               u16 startFrame;
               u16 endFrame;
               Vec3s rot;
               Vec3i startPos;
               Vec3i endPos;
               Vec3i normal;
} CsCmdActorAction;
typedef enum {
    CS_STATE_IDLE,
    CS_STATE_SKIPPABLE_INIT,
    CS_STATE_SKIPPABLE_EXEC,
    CS_STATE_UNSKIPPABLE_INIT,
    CS_STATE_UNSKIPPABLE_EXEC
} CutsceneState;
typedef enum {
    CS_CMD_00 = 0x0000,
    CS_CMD_CAMERA_POS = 0x0001,
    CS_CMD_CAMERA_FOCUS = 0x0002,
    CS_CMD_MISC = 0x0003,
    CS_CMD_SET_LIGHTING = 0x0004,
    CS_CMD_CAMERA_POS_LINK = 0x0005,
    CS_CMD_CAMERA_FOCUS_LINK = 0x0006,
    CS_CMD_07 = 0x0007,
    CS_CMD_08 = 0x0008,
    CS_CMD_09 = 0x0009,
    CS_CMD_TEXTBOX = 0x0013,
    CS_CMD_SET_ACTOR_ACTION_0 = 0x000A,
    CS_CMD_SET_ACTOR_ACTION_1 = 0x000F,
    CS_CMD_SET_ACTOR_ACTION_2 = 0x000E,
    CS_CMD_SET_ACTOR_ACTION_3 = 0x0019,
    CS_CMD_SET_ACTOR_ACTION_4 = 0x001D,
    CS_CMD_SET_ACTOR_ACTION_5 = 0x001E,
    CS_CMD_SET_ACTOR_ACTION_6 = 0x002C,
    CS_CMD_SET_ACTOR_ACTION_7 = 0x001F,
    CS_CMD_SET_ACTOR_ACTION_8 = 0x0031,
    CS_CMD_SET_ACTOR_ACTION_9 = 0x003E,
    CS_CMD_SET_ACTOR_ACTION_10 = 0x008F,
    CS_CMD_SCENE_TRANS_FX = 0x002D,
    CS_CMD_NOP = 0x000B,
    CS_CMD_PLAYBGM = 0x0056,
    CS_CMD_STOPBGM = 0x0057,
    CS_CMD_FADEBGM = 0x007C,
    CS_CMD_SETTIME = 0x008C,
    CS_CMD_TERMINATOR = 0x03E8,
    CS_CMD_END = 0xFFFF
} CutsceneCmd;
typedef struct {
               u32 sceneVromStart;
               u32 sceneVromEnd;
               u32 titleVromStart;
               u32 titleVromEnd;
               u8 unk_10;
               u8 config;
               u8 unk_12;
               u8 unk_13;
} Scene;
typedef struct {
               u8 code;
               u8 data1;
               u32 data2;
} SCmdBase;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdSpawnList;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdActorList;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdCsCameraList;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdColHeader;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdRoomList;
typedef struct {
               u8 code;
               u8 data1;
               char pad[2];
               s8 unk_04;
               s8 unk_05;
               s8 unk_06;
               u8 unk_07;
} SCmdWindSettings;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdEntranceList;
typedef struct {
               u8 code;
               u8 cUpElfMsgNum;
               u32 keepObjectId;
} SCmdSpecialFiles;
typedef struct {
               u8 code;
               u8 gpFlag1;
               u32 gpFlag2;
} SCmdRoomBehavior;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdMesh;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdObjectList;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdLightList;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdPathList;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdTransiActorList;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdLightSettingList;
typedef struct {
               u8 code;
               u8 data1;
               char pad[2];
               u8 hour;
               u8 min;
               u8 unk_06;
} SCmdTimeSettings;
typedef struct {
               u8 code;
               u8 data1;
               char pad[2];
               u8 skyboxId;
               u8 unk_05;
               u8 unk_06;
} SCmdSkyboxSettings;
typedef struct {
               u8 code;
               u8 data1;
               char pad[2];
               u8 unk_04;
               u8 unk_05;
} SCmdSkyboxDisables;
typedef struct {
               u8 code;
               u8 data1;
               u32 data2;
} SCmdEndMarker;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdExitList;
typedef struct {
               u8 code;
               u8 bgmId;
               char pad[4];
               u8 nighttimeSFX;
               u8 musicSeq;
} SCmdSoundSettings;
typedef struct {
               u8 code;
               u8 data1;
               char pad[5];
               u8 echo;
} SCmdEchoSettings;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdCutsceneData;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdAltHeaders;
typedef struct {
               u8 code;
               u8 cameraMovement;
               u32 area;
} SCmdMiscSettings;
typedef struct {
    u8 headerType;
} MeshHeaderBase;
typedef struct {
    MeshHeaderBase base;
    u8 numEntries;
    u32 dListStart;
    u32 dListEnd;
} MeshHeader0;
typedef struct {
    u32 opaqueDList;
    u32 translucentDList;
} MeshEntry0;
typedef struct {
    MeshHeaderBase base;
    u8 format;
    u32 entryRecord;
} MeshHeader1Base;
typedef struct {
    MeshHeader1Base base;
    u32 imagePtr;
    u32 unknown;
    u32 unknown2;
    u16 bgWidth;
    u16 bgHeight;
    u8 imageFormat;
    u8 imageSize;
    u16 imagePal;
    u16 imageFlip;
} MeshHeader1Single;
typedef struct {
    MeshHeader1Base base;
    u8 bgCnt;
    u32 bgRecordPtr;
} MeshHeader1Multi;
typedef struct {
    u16 unknown;
    s8 bgID;
    u32 imagePtr;
    u32 unknown2;
    u32 unknown3;
    u16 bgWidth;
    u16 bgHeight;
    u8 imageFmt;
    u8 imageSize;
    u16 imagePal;
    u16 imageFlip;
} BackgroundRecord;
typedef struct {
    s16 playerXMax, playerZMax;
    s16 playerXMin, playerZMin;
    u32 opaqueDList;
    u32 translucentDList;
} MeshEntry2;
typedef struct {
    MeshHeaderBase base;
    u8 numEntries;
    u32 dListStart;
    u32 dListEnd;
} MeshHeader2;
typedef struct {
    u8 ambientClrR, ambientClrG, ambientClrB;
    u8 diffuseClrA_R, diffuseClrA_G, diffuseClrA_B;
    u8 diffuseDirA_X, diffuseDirA_Y, diffuseDirA_Z;
    u8 diffuseClrB_R, diffuseClrB_G, diffuseClrB_B;
    u8 diffuseDirB_X, diffuseDirB_Y, diffuseDirB_Z;
    u8 fogClrR, fogClrG, fogClrB;
    u16 unk;
    u16 drawDistance;
} LightSettings;
typedef struct {
    s16 absMinX, absMinY, absMinZ;
    s16 absMaxX, absMaxY, absMaxZ;
    s16 numVerts;
    s32 vtxSegmentOffset;
    s16 numPolygons;
    s32 polySegmentOffset;
    s32 polyTypeDefSegmentOffset;
    s32 camDataSegmentOffset;
    s16 numWaterBoxes;
    s32 waterBoxSegmentOffset;
} ColHeader;
typedef struct {
    s16 cameraSType;
    s16 numCameras;
    s32 camPosDataSeg;
} CamData;
typedef struct {
    u32 unknown;
    u32 camPosDataSeg;
} CamPosDataEntry;
typedef struct {
    s16 posX, posY, posZ;
    s16 rotX, rotY, rotZ;
    s16 fov;
    s16 jfifId;
    s16 unk;
} CamPosData;
typedef struct {
    s16 type;
    s16 vtxA, vtxB, vtxC;
    s16 a, b, c, d;
} RoomPoly;
typedef struct {
    s16 xMin;
    s16 ySurface;
    s16 zMin;
    s16 xLength;
    s16 zLength;
    s32 properties;
} WaterBoxHeader;
typedef struct {
               u8 count;
               Vec3s* points;
} Path;
typedef union {
    SCmdBase base;
    SCmdSpawnList spawnList;
    SCmdActorList actorList;
    SCmdCsCameraList csCameraList;
    SCmdRoomList roomList;
    SCmdEntranceList entranceList;
    SCmdObjectList objectList;
    SCmdLightList lightList;
    SCmdPathList pathList;
    SCmdTransiActorList transiActorList;
    SCmdLightSettingList lightSettingList;
    SCmdExitList exitList;
    SCmdColHeader colHeader;
    SCmdMesh mesh;
    SCmdSpecialFiles specialFiles;
    SCmdCutsceneData cutsceneData;
    SCmdRoomBehavior roomBehavior;
    SCmdWindSettings windSettings;
    SCmdTimeSettings timeSettings;
    SCmdSkyboxSettings skyboxSettings;
    SCmdSkyboxDisables skyboxDisables;
    SCmdEndMarker endMarker;
    SCmdSoundSettings soundSettings;
    SCmdEchoSettings echoSettings;
    SCmdMiscSettings miscSettings;
    SCmdAltHeaders altHeaders;
} SceneCmd;
typedef enum {
               SCENE_YDAN,
               SCENE_DDAN,
               SCENE_BDAN,
               SCENE_BMORI1,
               SCENE_HIDAN,
               SCENE_MIZUSIN,
               SCENE_JYASINZOU,
               SCENE_HAKADAN,
               SCENE_HAKADANCH,
               SCENE_ICE_DOUKUTO,
               SCENE_GANON,
               SCENE_MEN,
               SCENE_GERUDOWAY,
               SCENE_GANONTIKA,
               SCENE_GANON_SONOGO,
               SCENE_GANONTIKA_SONOGO,
               SCENE_TAKARAYA,
               SCENE_YDAN_BOSS,
               SCENE_DDAN_BOSS,
               SCENE_BDAN_BOSS,
               SCENE_MORIBOSSROOM,
               SCENE_FIRE_BS,
               SCENE_MIZUSIN_BS,
               SCENE_JYASINBOSS,
               SCENE_HAKADAN_BS,
               SCENE_GANON_BOSS,
               SCENE_GANON_FINAL,
               SCENE_ENTRA,
               SCENE_ENTRA_N,
               SCENE_ENRUI,
               SCENE_MARKET_ALLEY,
               SCENE_MARKET_ALLEY_N,
               SCENE_MARKET_DAY,
               SCENE_MARKET_NIGHT,
               SCENE_MARKET_RUINS,
               SCENE_SHRINE,
               SCENE_SHRINE_N,
               SCENE_SHRINE_R,
               SCENE_KOKIRI_HOME,
               SCENE_KOKIRI_HOME3,
               SCENE_KOKIRI_HOME4,
               SCENE_KOKIRI_HOME5,
               SCENE_KAKARIKO,
               SCENE_KAKARIKO3,
               SCENE_SHOP1,
               SCENE_KOKIRI_SHOP,
               SCENE_GOLON,
               SCENE_ZOORA,
               SCENE_DRAG,
               SCENE_ALLEY_SHOP,
               SCENE_NIGHT_SHOP,
               SCENE_FACE_SHOP,
               SCENE_LINK_HOME,
               SCENE_IMPA,
               SCENE_MALON_STABLE,
               SCENE_LABO,
               SCENE_HYLIA_LABO,
               SCENE_TENT,
               SCENE_HUT,
               SCENE_DAIYOUSEI_IZUMI,
               SCENE_YOUSEI_IZUMI_TATE,
               SCENE_YOUSEI_IZUMI_YOKO,
               SCENE_KAKUSIANA,
               SCENE_HAKAANA,
               SCENE_HAKAANA2,
               SCENE_HAKAANA_OUKE,
               SCENE_SYATEKIJYOU,
               SCENE_TOKINOMA,
               SCENE_KENJYANOMA,
               SCENE_HAIRAL_NIWA,
               SCENE_HAIRAL_NIWA_N,
               SCENE_HIRAL_DEMO,
               SCENE_HAKASITARELAY,
               SCENE_TURIBORI,
               SCENE_NAKANIWA,
               SCENE_BOWLING,
               SCENE_SOUKO,
               SCENE_MIHARIGOYA,
               SCENE_MAHOUYA,
               SCENE_GANON_DEMO,
               SCENE_KINSUTA,
               SCENE_SPOT00,
               SCENE_SPOT01,
               SCENE_SPOT02,
               SCENE_SPOT03,
               SCENE_SPOT04,
               SCENE_SPOT05,
               SCENE_SPOT06,
               SCENE_SPOT07,
               SCENE_SPOT08,
               SCENE_SPOT09,
               SCENE_SPOT10,
               SCENE_SPOT11,
               SCENE_SPOT12,
               SCENE_SPOT13,
               SCENE_SPOT15,
               SCENE_SPOT16,
               SCENE_SPOT17,
               SCENE_SPOT18,
               SCENE_SPOT20,
               SCENE_GANON_TOU,
               SCENE_TEST01,
               SCENE_BESITU,
               SCENE_DEPTH_TEST,
               SCENE_SYOTES,
               SCENE_SYOTES2,
               SCENE_SUTARU,
               SCENE_HAIRAL_NIWA2,
               SCENE_SASATEST,
               SCENE_TESTROOM
} SceneID;
typedef struct {
    u8 r, g, b;
} Color_RGB8;
typedef struct {
    u8 r, g, b, a;
} Color_RGBA8;
typedef struct {
    f32 r, g, b, a;
} Color_RGBAf;
typedef struct {
                 char unk_00[0x184];
                 Color_RGBA8 p1Start;
                 Color_RGBA8 p2Start;
                 Color_RGBA8 p1End;
                 Color_RGBA8 p2End;
                 u32 unk_194;
                 u32 unk_198;
                 u32 unk_19C;
} TrailEffect;
typedef enum {
               EQUIP_SWORD,
               EQUIP_SHIELD,
               EQUIP_TUNIC,
               EQUIP_BOOTS
} EquipmentType;
typedef enum {
               UPG_QUIVER,
               UPG_BOMB_BAG,
               UPG_STRENGTH,
               UPG_SCALE,
               UPG_WALLET,
               UPG_BULLET_BAG,
               UPG_STICKS,
               UPG_NUTS
} UpgradeType;
typedef enum {
               SLOT_STICK,
               SLOT_NUT,
               SLOT_BOMB,
               SLOT_BOW,
               SLOT_ARROW_FIRE,
               SLOT_DINS_FIRE,
               SLOT_SLINGSHOT,
               SLOT_OCARINA,
               SLOT_BOMBCHU,
               SLOT_HOOKSHOT,
               SLOT_ARROW_ICE,
               SLOT_FARORES_WIND,
               SLOT_BOOMERANG,
               SLOT_LENS,
               SLOT_BEAN,
               SLOT_HAMMER,
               SLOT_ARROW_LIGHT,
               SLOT_NAYRUS_LOVE,
               SLOT_BOTTLE_1,
               SLOT_BOTTLE_2,
               SLOT_BOTTLE_3,
               SLOT_BOTTLE_4,
               SLOT_TRADE_ADULT,
               SLOT_TRADE_CHILD,
               SLOT_NONE = 0xFF
} InventorySlot;
typedef enum {
               ITEM_STICK,
               ITEM_NUT,
               ITEM_BOMB,
               ITEM_BOW,
               ITEM_ARROW_FIRE,
               ITEM_DINS_FIRE,
               ITEM_SLINGSHOT,
               ITEM_OCARINA_FAIRY,
               ITEM_OCARINA_TIME,
               ITEM_BOMBCHU,
               ITEM_HOOKSHOT,
               ITEM_LONGSHOT,
               ITEM_ARROW_ICE,
               ITEM_FARORES_WIND,
               ITEM_BOOMERANG,
               ITEM_LENS,
               ITEM_BEAN,
               ITEM_HAMMER,
               ITEM_ARROW_LIGHT,
               ITEM_NAYRUS_LOVE,
               ITEM_BOTTLE,
               ITEM_POTION_RED,
               ITEM_POTION_GREEN,
               ITEM_POTION_BLUE,
               ITEM_FAIRY,
               ITEM_FISH,
               ITEM_MILK_BOTTLE,
               ITEM_LETTER_RUTO,
               ITEM_BLUE_FIRE,
               ITEM_BUG,
               ITEM_BIG_POE,
               ITEM_MILK_HALF,
               ITEM_POE,
               ITEM_WEIRD_EGG,
               ITEM_CHICKEN,
               ITEM_LETTER_ZELDA,
               ITEM_MASK_KEATON,
               ITEM_MASK_SKULL,
               ITEM_MASK_SPOOKY,
               ITEM_MASK_BUNNY,
               ITEM_MASK_GORON,
               ITEM_MASK_ZORA,
               ITEM_MASK_GERUDO,
               ITEM_MASK_TRUTH,
               ITEM_SOLD_OUT,
               ITEM_POCKET_EGG,
               ITEM_POCKET_CUCCO,
               ITEM_COJIRO,
               ITEM_ODD_MUSHROOM,
               ITEM_ODD_POTION,
               ITEM_SAW,
               ITEM_SWORD_BROKEN,
               ITEM_PRESCRIPTION,
               ITEM_FROG,
               ITEM_EYEDROPS,
               ITEM_CLAIM_CHECK,
               ITEM_BOW_ARROW_FIRE,
               ITEM_BOW_ARROW_ICE,
               ITEM_BOW_ARROW_LIGHT,
               ITEM_SWORD_KOKIRI,
               ITEM_SWORD_MASTER,
               ITEM_SWORD_BGS,
               ITEM_SHIELD_DEKU,
               ITEM_SHIELD_HYLIAN,
               ITEM_SHIELD_MIRROR,
               ITEM_TUNIC_KOKIRI,
               ITEM_TUNIC_GORON,
               ITEM_TUNIC_ZORA,
               ITEM_BOOTS_KOKIRI,
               ITEM_BOOTS_IRON,
               ITEM_BOOTS_HOVER,
               ITEM_BULLET_BAG_30,
               ITEM_BULLET_BAG_40,
               ITEM_BULLET_BAG_50,
               ITEM_QUIVER_30,
               ITEM_QUIVER_40,
               ITEM_QUIVER_50,
               ITEM_BOMB_BAG_20,
               ITEM_BOMB_BAG_30,
               ITEM_BOMB_BAG_40,
               ITEM_BRACELET,
               ITEM_GAUNTLETS_SILVER,
               ITEM_GAUNTLETS_GOLD,
               ITEM_SCALE_SILVER,
               ITEM_SCALE_GOLDEN,
               ITEM_SWORD_KNIFE,
               ITEM_WALLET_ADULT,
               ITEM_WALLET_GIANT,
               ITEM_SEEDS,
               ITEM_FISHING_POLE,
               ITEM_SONG_MINUET,
               ITEM_SONG_BOLERO,
               ITEM_SONG_SERENADE,
               ITEM_SONG_REQUIEM,
               ITEM_SONG_NOCTURNE,
               ITEM_SONG_PRELUDE,
               ITEM_SONG_LULLABY,
               ITEM_SONG_EPONA,
               ITEM_SONG_SARIA,
               ITEM_SONG_SUN,
               ITEM_SONG_TIME,
               ITEM_SONG_STORMS,
               ITEM_MEDALLION_FOREST,
               ITEM_MEDALLION_FIRE,
               ITEM_MEDALLION_WATER,
               ITEM_MEDALLION_SPIRIT,
               ITEM_MEDALLION_SHADOW,
               ITEM_MEDALLION_LIGHT,
               ITEM_KOKIRI_EMERALD,
               ITEM_GORON_RUBY,
               ITEM_ZORA_SAPPHIRE,
               ITEM_STONE_OF_AGONY,
               ITEM_GERUDO_CARD,
               ITEM_SKULL_TOKEN,
               ITEM_HEART_CONTAINER,
               ITEM_HEART_PIECE,
               ITEM_KEY_BOSS,
               ITEM_COMPASS,
               ITEM_DUNGEON_MAP,
               ITEM_KEY_SMALL,
               ITEM_MAGIC_SMALL,
               ITEM_MAGIC_LARGE,
               ITEM_HEART_PIECE_2,
               ITEM_INVALID_1,
               ITEM_INVALID_2,
               ITEM_INVALID_3,
               ITEM_INVALID_4,
               ITEM_INVALID_5,
               ITEM_INVALID_6,
               ITEM_INVALID_7,
               ITEM_MILK,
               ITEM_HEART,
               ITEM_RUPEE_GREEN,
               ITEM_RUPEE_BLUE,
               ITEM_RUPEE_RED,
               ITEM_RUPEE_PURPLE,
               ITEM_RUPEE_GOLD,
               ITEM_INVALID_8,
               ITEM_STICKS_5,
               ITEM_STICKS_10,
               ITEM_NUTS_5,
               ITEM_NUTS_10,
               ITEM_BOMBS_5,
               ITEM_BOMBS_10,
               ITEM_BOMBS_20,
               ITEM_BOMBS_30,
               ITEM_ARROWS_SMALL,
               ITEM_ARROWS_MEDIUM,
               ITEM_ARROWS_LARGE,
               ITEM_SEEDS_30,
               ITEM_BOMBCHUS_5,
               ITEM_BOMBCHUS_20,
               ITEM_STICK_UPGRADE_20,
               ITEM_STICK_UPGRADE_30,
               ITEM_NUT_UPGRADE_30,
               ITEM_NUT_UPGRADE_40,
               ITEM_NONE = 0xFF
} ItemID;
typedef enum {
               GI_INVALID,
               GI_BOMBS_5,
               GI_NUTS_5,
               GI_BOMBCHUS_10,
               GI_BOW,
               GI_SLINGSHOT,
               GI_BOOMERANG,
               GI_STICKS_1,
               GI_HOOKSHOT,
               GI_LONGSHOT,
               GI_LENS,
               GI_LETTER_ZELDA,
               GI_OCARINA_OOT,
               GI_HAMMER,
               GI_COJIRO,
               GI_BOTTLE,
               GI_POTION_RED,
               GI_POTION_GREEN,
               GI_POTION_BLUE,
               GI_FAIRY,
               GI_MILK_BOTTLE,
               GI_LETTER_RUTO,
               GI_BEAN,
               GI_MASK_SKULL,
               GI_MASK_SPOOKY,
               GI_CHICKEN,
               GI_MASK_KEATON,
               GI_MASK_BUNNY,
               GI_MASK_TRUTH,
               GI_POCKET_EGG,
               GI_POCKET_CUCCO,
               GI_ODD_MUSHROOM,
               GI_ODD_POTION,
               GI_SAW,
               GI_SWORD_BROKEN,
               GI_PERSCRIPTION,
               GI_FROG,
               GI_EYEDROPS,
               GI_CLAIM_CHECK,
               GI_SWORD_KOKIRI,
               GI_SWORD_KNIFE,
               GI_SHIELD_DEKU,
               GI_SHIELD_HYLIAN,
               GI_SHIELD_MIRROR,
               GI_TUNIC_GORON,
               GI_TUNIC_ZORA,
               GI_BOOTS_IRON,
               GI_BOOTS_HOVER,
               GI_QUIVER_40,
               GI_QUIVER_50,
               GI_BOMB_BAG_20,
               GI_BOMB_BAG_30,
               GI_BOMB_BAG_40,
               GI_GAUNTLETS_SILVER,
               GI_GAUNTLETS_GOLD,
               GI_SCALE_SILVER,
               GI_SCALE_GOLD,
               GI_STONE_OF_AGONY,
               GI_GERUDO_CARD,
               GI_OCARINA_FAIRY,
               GI_SEEDS_5,
               GI_HEART_CONTAINER,
               GI_HEART_PIECE,
               GI_KEY_BOSS,
               GI_COMPASS,
               GI_MAP,
               GI_KEY_SMALL,
               GI_MAGIC_SMALL,
               GI_MAGIC_LARGE,
               GI_WALLET_ADULT,
               GI_WALLET_GIANT,
               GI_WEIRD_EGG,
               GI_HEART,
               GI_ARROWS_SMALL,
               GI_ARROWS_MEDIUM,
               GI_ARROWS_LARGE,
               GI_RUPEE_GREEN,
               GI_RUPEE_BLUE,
               GI_RUPEE_RED,
               GI_HEART_CONTAINER_2,
               GI_MILK,
               GI_MASK_GORON,
               GI_MASK_ZORA,
               GI_MASK_GERUDO,
               GI_BRACELET,
               GI_RUPEE_PURPLE,
               GI_RUPEE_GOLD,
               GI_SWORD_BGS,
               GI_ARROW_FIRE,
               GI_ARROW_ICE,
               GI_ARROW_LIGHT,
               GI_SKULL_TOKEN,
               GI_DINS_FIRE,
               GI_FARORES_WIND,
               GI_NAYRUS_LOVE,
               GI_BULLET_BAG_30,
               GI_BULLET_BAG_40,
               GI_STICKS_5,
               GI_STICKS_10,
               GI_NUTS_5_2,
               GI_NUTS_10,
               GI_BOMBS_1,
               GI_BOMBS_10,
               GI_BOMBS_20,
               GI_BOMBS_30,
               GI_SEEDS_30,
               GI_BOMBCHUS_5,
               GI_BOMBCHUS_20,
               GI_FISH,
               GI_BUGS,
               GI_BLUE_FIRE,
               GI_POE,
               GI_BIG_POE,
               GI_DOOR_KEY,
               GI_RUPEE_GREEN_LOSE,
               GI_RUPEE_BLUE_LOSE,
               GI_RUPEE_RED_LOSE,
               GI_RUPEE_PURPLE_LOSE,
               GI_HEART_PIECE_WIN,
               GI_STICK_UPGRADE_20,
               GI_STICK_UPGRADE_30,
               GI_NUT_UPGRADE_30,
               GI_NUT_UPGRADE_40,
               GI_BULLET_BAG_50,
               GI_ICE_TRAP,
               GI_TEXT_0
} GetItemID;
typedef struct {
    u32 cont: 1;
    u32 type: 4;
    u32 offset: 11;
    s32 value: 16;
} InitChainEntry;
typedef enum {
              ICHAINTYPE_U8,
              ICHAINTYPE_S8,
              ICHAINTYPE_U16,
              ICHAINTYPE_S16,
              ICHAINTYPE_U32,
              ICHAINTYPE_S32,
              ICHAINTYPE_F32,
              ICHAINTYPE_F32_DIV1000,
              ICHAINTYPE_VEC3F,
              ICHAINTYPE_VEC3F_DIV1000,
              ICHAINTYPE_VEC3S
} InitChainType;
typedef char *va_list;
typedef struct {
               s32 regPage;
               s32 regGroup;
               s32 regCur;
               s32 dpadLast;
               s32 repeat;
               s16 data[29 * 6 * 16];
} GameInfo;
typedef struct {
               u8 button_items[4];
               u8 c_button_slots[3];
               u16 equipment;
} ItemEquips;
typedef struct {
               u32 chest;
               u32 swch;
               u32 clear;
               u32 collect;
               u32 unk;
               u32 rooms_1;
               u32 rooms_2;
} SaveSceneFlags;
typedef struct {
               s16 scene;
               Vec3s pos;
               s16 angle;
} HorseData;
typedef struct {
               Vec3f pos;
               s16 yaw;
               s16 player_params;
               s16 entrance_index;
               u8 room_index;
               s8 data;
               u32 temp_swch_flags;
               u32 temp_collect_flags;
} RespawnData;
typedef enum {
               RESPAWN_MODE_DOWN,
               RESPAWN_MODE_RETURN,
               RESPAWN_MODE_TOP
} RespawnMode;
typedef enum {
               BTN_ENABLED,
               BTN_DISABLED = 0xFF
} ButtonStatus;
typedef struct {
                 s32 entrance_index;
                 s32 link_age;
                 s32 cutscene_index;
                 u16 day_time;
                 s32 night_flag;
                 s32 unk_14;
                 s32 unk_18;
                 char newf[6];
                 s16 deaths;
                 char player_name[8];
                 s16 n64dd_flag;
                 s16 health_capacity;
                 s16 health;
                 s8 magic_level;
                 s8 magic;
                 s16 rupees;
                 u16 bgs_hits_left;
                 u16 navi_timer;
                 u8 magic_acquired;
                 char unk_3B[0x0001];
                 u8 double_magic;
                 u8 double_defense;
                 s8 bgs_flag;
                 char unk_3F;
                 ItemEquips child_equips;
                 ItemEquips adult_equips;
                 char unk_54[0x0014];
                 ItemEquips equips;
                 char unk_72[0x0002];
                 u8 items[24];
                 s8 ammo[16];
                 u16 equipment;
                 u32 upgrades;
                 u32 quest_items;
                 u8 dungeon_items[20];
                 s8 dungeon_keys[19];
                 s8 defense_hearts;
                 s16 gs_tokens;
                 SaveSceneFlags scene_flags[124];
    struct {
                     s32 pos_x;
                     s32 pos_y;
                     s32 pos_z;
                     s32 yaw;
                     s32 player_params;
                     s32 entrance_index;
                     s32 room_index;
                     s32 set;
                     s32 temp_swch_flags;
                     s32 temp_collect_flags;
    } fw;
                 char unk_E8C[0x0010];
                 u8 gs_flags[24];
                 char unk_EB4[0x0020];
                 u16 event_chk_inf[14];
                 u16 item_get_inf[4];
                 u16 inf_table[30];
                 char unk_F34[0x0004];
                 u32 world_map_area_data;
                 char unk_F3C[0x040C];
                 HorseData horse_data;
                 u16 checksum;
                 s32 file_num;
                 char unk_1358[0x0004];
                 s32 game_mode;
                 s32 scene_setup_index;
                 s32 respawn_flag;
                 RespawnData respawn[3];
                 char unk_13BC[0x0008];
                 s16 dogParams;
                 char unk_13C6[0x0001];
                 u8 unk_13C7;
                 u16 nayrus_love_timer;
                 char unk_13CA[0x0002];
                 s16 rupee_accumulator;
                 s16 timer_1_state;
                 s16 timer_1_value;
                 s16 timer_2_state;
                 s16 timer_2_value;
                 s16 timer_x[2];
                 s16 timer_y[2];
                 char unk_13DE[0x0002];
                 u8 seq_index;
                 u8 night_sfx;
                 u8 button_status[5];
                 u8 unk_13E7;
                 u16 unk_13E8;
                 u16 unk_13EA;
                 u16 unk_13EC;
                 u16 unk_13EE;
                 s16 unk_13F0;
                 s16 unk_13F2;
                 s16 unk_13F4;
                 s16 unk_13F6;
                 s16 unk_13F8;
                 u16 event_inf[4];
                 u16 dungeon_index;
                 u16 minigame_state;
                 u16 minigame_score;
                 char unk_1408[0x0001];
                 u8 language;
                 u8 audio_settings;
                 char unk_140B[0x0001];
                 u8 z_targeting;
                 u16 unk_140E;
                 u8 unk_1410;
                 u8 unk_1411;
                 u16 next_cutscene_index;
                 u8 cutscene_trigger;
                 u8 chamber_cutscene_num;
                 u16 next_day_time;
                 u8 fade_duration;
                 u8 unk_1419;
                 u16 environment_time;
                 u8 dogIsLost;
                 u8 transition_type;
                 char unk_141E[0x0002];
                 s16 world_map_area;
                 s16 unk_1422;
                 s16 health_accumulator;
} SaveContext;
typedef struct {
                  u16 headMagic;
                  Gfx polyOpaBuffer[0x17E0];
                  Gfx polyXluBuffer[0x800];
                  Gfx overlayBuffer[0x400];
                  Gfx workBuffer[0x80];
                  Gfx unusedBuffer[0x20];
                  u16 tailMagic;
} GfxPool;
typedef struct {
                 u32 size;
                 u8* bufp;
                 u8* head;
                 u8* tail;
} TwoHeadArena;
typedef struct {
                 u32 size;
                 Gfx* bufp;
                 Gfx* p;
                 Gfx* d;
} TwoHeadGfxArena;
typedef struct OSScTask {
               struct OSScTask* next;
               u32 state;
               u32 flags;
               void* framebuffer;
               OSTask list;
               OSMesgQueue* msgQ;
               OSMesg msg;
} OSScTask;
typedef struct GraphicsContext {
                 Gfx* polyOpaBuffer;
                 Gfx* polyXluBuffer;
                 char unk_008[0x08];
                 Gfx* overlayBuffer;
                 u32 unk_014;
                 char unk_018[0x20];
                 OSMesg msgBuff[0x08];
                 OSMesgQueue* schedMsgQ;
                 OSMesgQueue queue;
                 char unk_074[0x04];
                 OSScTask task;
                 char unk_0D0[0xE0];
                 Gfx* workBuffer;
                 TwoHeadGfxArena work;
                 char unk_01C4[0xC0];
                 OSViMode* viMode;
                 char unk_0288[0x20];
                 TwoHeadGfxArena overlay;
                 TwoHeadGfxArena polyOpa;
                 TwoHeadGfxArena polyXlu;
                 u32 gfxPoolIdx;
                 u16* curFrameBuffer;
                 char unk_2E0[0x04];
                 u32 viFeatures;
                 s32 fbIdx;
                 void (*callback)(struct GraphicsContext*, u32);
                 u32 callbackParam;
                 f32 xScale;
                 f32 yScale;
                 char unk_2FC[0x04];
} GraphicsContext;
typedef struct {
               union {
        struct {
            u16 a : 1;
            u16 b : 1;
            u16 z : 1;
            u16 s : 1;
            u16 du : 1;
            u16 dd : 1;
            u16 dl : 1;
            u16 dr : 1;
            u16 : 2;
            u16 l : 1;
            u16 r : 1;
            u16 cu : 1;
            u16 cd : 1;
            u16 cl : 1;
            u16 cr : 1;
        };
        u16 pad;
    };
               s8 x;
               s8 y;
} RawInput;
typedef struct {
               RawInput raw;
               u16 status;
               RawInput rawPrev;
               u16 statusPrev;
               u16 padPressed;
               s8 xDiff;
               s8 yDiff;
               char unk_10[0x02];
               u16 padReleased;
               s8 xAdjusted;
               s8 yAdjusted;
               char unk_16[0x02];
} Input;
typedef struct {
                s16 unk_0;
                s16 unk_2;
                u16 unk_4;
                u16 unk_6;
                s16 unk_8;
                s16 unk_A;
                u16 unk_C;
                u16 unk_E;
} UnkViewStruct;
typedef struct {
                s32 topY;
                s32 bottomY;
                s32 leftX;
                s32 rightX;
} Viewport;
typedef struct {
                 s32 magic;
                 GraphicsContext* gfxCtx;
                 Viewport viewport;
                 f32 fieldOfView;
                 f32 fogDistance;
                 f32 zDepth;
                 f32 unk_24;
                 Vec3f eye;
                 Vec3f unk_34;
                 Vec3f unk_40;
                 char unk_4C[0x04];
                 Viewport unk_50;
                 Mtx unk_60;
                 MtxF unk_A0;
                 Mtx* unk_E0;
                 MtxF* unk_E4;
                 Vec3f unk_E8;
                 Vec3f unk_F4;
                 f32 unk_100;
                 Vec3f unk_104;
                 Vec3f unk_110;
                 u16 unk_11C;
                 u16 unk_11E;
                 s32 unk_120;
                 s32 unk_124;
} View;
typedef struct {
    f32 unk_00;
    s16 unk_04;
    s16 unk_06;
} struct_80045714;
typedef struct {
                 s32 unk_00;
                 s16 unk_04;
                 s16 unk_06;
                 s16 unk_08;
                 s16 unk_0A;
                 char unk_0C[0x44];
                 Vec3f unk_50;
                 Vec3f unk_5C;
                 char unk_68[0x0C];
                 Vec3f unk_74;
                 Vec3f unk_80;
                 struct GlobalContext *globalCtx;
                 Player *player;
                 PosRot unk_94;
                 char unk_A8[0x18];
                 Vec3f unk_C0;
                 Vec3f unk_CC;
                 f32 unk_D8;
                 f32 unk_DC;
                 f32 unk_E0;
                 Vec3f unk_E4;
                 char unk_F0[0x0C];
                 f32 unk_FC;
                 f32 unk_100;
                 f32 unk_104;
                 Vec3f unk_108;
                 char unk_114[0x10];
                 s32 unk_124;
                 s32 unk_128;
                 s16 unk_12C;
                 s16 unk_12E;
                 char unk_130[0x10];
                 s16 unk_140;
                 s16 unk_142;
                 s16 unk_144;
                 s16 unk_146;
                 s16 unk_148;
                 s16 unk_14A;
                 s16 unk_14C;
                 s16 unk_14E;
                 s16 unk_150;
                 s16 unk_152;
                 u16 unk_154;
                 s16 unk_156;
                 s16 unk_158;
                 s16 unk_15A;
                 s16 unk_15C;
                 u16 unk_15E;
                 s16 unk_160;
                 s16 unk_162;
                 s16 unk_164;
                 s16 unk_166;
                 s16 unk_168;
                 s16 unk_16A;
} Camera;
typedef struct {
                 Camera activeCameras[4];
                 Camera* activeCameraPtrs[4];
                 s16 unk_5C0;
                 s16 unk_5C2;
} CameraContext;
typedef struct {
               u8 musicSeq;
               u8 nighttimeSFX;
               char unk_02[0x2];
} SoundContext;
typedef struct {
               char unk_00[0x50];
} StaticCollisionContext;
typedef struct {
                 char unk_00[0x04];
                 ActorMesh actorMeshArr[50];
                 u16 flags[50];
                 char unk_13F0[0x24];
} DynaCollisionContext;
typedef struct {
                 StaticCollisionContext stat;
                 DynaCollisionContext dyna;
} CollisionContext;
typedef struct {
               Vec3f pos;
               f32 unk_0C;
               Color_RGB8 color;
} TargetContextEntry;
typedef struct {
               Vec3f naviRefPos;
               Vec3f targetCenterPos;
               Color_RGBAf naviInner;
               Color_RGBAf naviOuter;
               Actor* arrowPointedActor;
               Actor* targetedActor;
               f32 unk_40;
               f32 unk_44;
               s16 unk_48;
               u8 activeType;
               u8 unk_4B;
               s8 unk_4C;
               char unk_4D[0x03];
               TargetContextEntry arr_50[3];
               Actor* unk_8C;
               Actor* unk_90;
               Actor* unk_94;
} TargetContext;
typedef struct {
               u32 texture;
               s16 unk_4;
               s16 unk_6;
               u8 unk_8;
               u8 unk_9;
               u8 delayA;
               u8 delayB;
               s16 unk_C;
               s16 unk_E;
} TitleCardContext;
typedef struct {
               u32 length;
               Actor* first;
} ActorListEntry;
typedef struct {
                 u8 unk_00;
                 char unk_01[0x01];
                 u8 unk_02;
                 u8 unk_03;
                 char unk_04[0x04];
                 u8 total;
                 char unk_09[0x03];
                 ActorListEntry actorList[12];
                 TargetContext targetCtx;
    struct {
                     u32 swch;
                     u32 tempSwch;
                     u32 unk0;
                     u32 unk1;
                     u32 chest;
                     u32 clear;
                     u32 tempClear;
                     u32 collect;
                     u32 tempCollect;
    } flags;
                 TitleCardContext titleCtx;
                 char unk_138[0x04];
                 void* absoluteSpace;
} ActorContext;
typedef struct {
               char unk_00[0x4];
               void* segment;
               u8 state;
               f32 unk_0C;
               u16 frames;
               u16 unk_12;
    union {
                   s32 unk_14_all;
        struct {
            s16 unk_14;
            s16 unk_16;
        };
    };
               u16 unk_18;
               u8 unk_1A;
               u8 unk_1B;
               CutsceneCameraPoint* cameraFocus;
               CutsceneCameraPoint* cameraPosition;
               CsCmdActorAction* linkAction;
               CsCmdActorAction* actorActions[10];
} CutsceneContext;
typedef struct {
                 View view;
                 char unk_128[0xE188];
                 void* textboxSegment;
                 char unk_E2B4[0x44];
                 u16 unk_E2F8;
                 u16 unk_E2FA;
                 char unk_E2FC[0x04];
                 s32 unk_E300;
                 u8 msgMode;
                 char unk_E305[0xD1];
                 u16 unk_E3D6;
                 char unk_E3D8[0x0A];
                 u16 unk_E3E2;
                 u8 unk_E3E4;
                 u8 choiceIndex;
                 char unk_E3E6[0x08];
                 u16 unk_E3EE;
                 u16 unk_E3F0;
                 char unk_E3F2[0x02];
                 u16 unk_E3F4;
                 char unk_E3F6[0x16];
                 u16 unk_E40C;
                 char unk_E40E[0x0A];
} MessageContext;
typedef struct {
                 View view;
                 Vtx* vtx_128;
                 Vtx* vtx_12C;
                 void* parameterSegment;
                 void* do_actionSegment;
                 void* icon_itemSegment;
                 void* mapSegment;
                 char unk_140[0x20];
                 DmaRequest dmaRequest_160;
                 DmaRequest dmaRequest_180;
                 char unk_1A0[0x20];
                 OSMesgQueue loadQueue;
                 OSMesg loadMsg;
                 s32 unk_1DC[4];
                 s16 unk_1EC;
                 u16 unk_1EE;
                 u16 unk_1F0;
                 f32 unk_1F4;
                 s16 naviCalling;
                 s16 unk_1FA;
                 s16 unk_1FC;
                 s16 unk_1FE;
                 s16 unk_200;
                 s16 unk_202[3];
                 s16 unk_208[3];
                 s16 unk_20E[6];
                 s16 unk_21A[6];
                 s16 unk_226;
                 s16 unk_228;
                 s16 unk_22A;
                 s16 unk_22C;
                 s16 unk_22E;
                 s16 unk_230;
                 s16 counterDigits[4];
                 u8 unk_23A;
                 u16 unk_23C;
                 u16 hbaAmmo;
                 u16 unk_240;
                 u16 unk_242;
                 u16 unk_244;
                 u16 aAlpha;
                 u16 bAlpha;
                 u16 cLeftAlpha;
                 u16 cDownAlpha;
                 u16 cRightAlpha;
                 u16 healthAlpha;
                 u16 magicAlpha;
                 u16 minimapAlpha;
                 s16 startAlpha;
                 char unk_258[0x004];
                 s16 roomNum;
                 char unk_25E[0x002];
                 u8 unk_260;
                 u8 unk_261;
    struct {
                     u8 hGauge;
                     u8 bButton;
                     u8 aButton;
                     u8 bottles;
                     u8 tradeItems;
                     u8 hookshot;
                     u8 ocarina;
                     u8 warpSongs;
                     u8 sunsSong;
                     u8 farores;
                     u8 dinsNayrus;
                     u8 all;
    } restrictions;
} InterfaceContext;
typedef struct {
                 View view;
                 void* unk_128;
                 char unk_12C[0x03C];
                 Vtx* vtx_168;
                 char unk_16C[0x068];
                 u16 state;
                 u16 flag;
                 char unk_1D8[0x00C];
                 u16 unk_1E4;
                 char unk_1E6[0x006];
                 u16 unk_1EC;
                 char unk_1EE[0x04A];
                 u16 unk_238;
                 char unk_23A[0x004];
                 u16 unk_23E;
                 char unk_240[0x00E];
                 u16 unk_24E;
                 char unk_250[0x004];
                 s16 unk_254;
                 s16 unk_256;
                 s16 unk_258;
                 char unk_25A[0x066];
} PauseContext;
typedef struct {
               s16 id;
               void* segment;
               DmaRequest dmaRequest;
               OSMesgQueue loadQueue;
               OSMesg loadMsg;
} ObjectStatus;
typedef struct {
                 void* spaceStart;
                 void* spaceEnd;
                 u8 num;
                 u8 unk_09;
                 u8 mainKeepIndex;
                 u8 subKeepIndex;
                 ObjectStatus status[19];
} ObjectContext;
typedef struct {
               Gfx* opa;
               Gfx* xlu;
} PolygonDlist;
typedef struct {
               u8 type;
               u8 num;
               void* start;
               void* end;
} Polygon;
typedef struct {
               u8 type;
               u8 num;
               void* start;
               void* end;
} PolygonType0;
typedef struct {
               u16 unk_00;
               u8 id;
               u32 source;
               u32 unk_0C;
               u32 tlut;
               u16 width;
               u16 height;
               u8 fmt;
               u8 siz;
               u16 mode0;
               u16 tlutCount;
} BgImage;
typedef struct {
               u8 type;
               u8 format;
               void* dlist;
    union {
        struct {
                       u32 source;
                       u32 unk_0C;
                       u32 tlut;
                       u16 width;
                       u16 height;
                       u8 fmt;
                       u8 siz;
                       u16 mode0;
                       u16 tlutCount;
        } single;
        struct {
                       u8 count;
                       BgImage* list;
        } multi;
    };
} PolygonType1;
typedef struct {
               Vec3s pos;
               s16 unk_06;
               Gfx* opa;
               Gfx* xlu;
} PolygonDlist2;
typedef struct {
               u8 type;
               u8 num;
               void* start;
               void* end;
} PolygonType2;
typedef union {
    Polygon polygon;
    PolygonType0 polygon0;
    PolygonType1 polygon1;
    PolygonType2 polygon2;
} Mesh;
typedef struct {
               s8 num;
               u8 unk_01;
               u8 unk_02;
               u8 unk_03;
               s8 echo;
               u8 showInvisActors;
               Mesh* mesh;
               void* segment;
               char unk_10[0x4];
} Room;
typedef struct {
               Room curRoom;
               Room prevRoom;
               void* bufPtrs[2];
               u8 unk_30;
               s8 status;
               void* unk_34;
               DmaRequest dmaRequest;
               OSMesgQueue loadQueue;
               OSMesg loadMsg;
} RoomContext;
typedef struct {
               char unk_00[0x028C];
} SubGlobalContext11E60;
typedef struct {
               s16 id;
               Vec3s pos;
               Vec3s rot;
               s16 params;
} ActorEntry;
typedef struct {
               s8 frontRoom;
               s8 frontEffects;
               s8 backRoom;
               s8 backEffects;
               s16 id;
               Vec3s pos;
               s16 rotY;
               s16 params;
} TransitionActorEntry;
typedef struct {
               u8 spawn;
               u8 room;
} EntranceEntry;
typedef struct {
               u32 vromStart;
               u32 vromEnd;
} RomFile;
typedef struct {
               void* read_buff;
} Sram;
typedef struct GameAllocEntry {
               struct GameAllocEntry* next;
               struct GameAllocEntry* prev;
               u32 size;
               u32 unk_0C;
} GameAllocEntry;
typedef struct {
               GameAllocEntry base;
               GameAllocEntry* head;
} GameAlloc;
typedef struct GameState {
               GraphicsContext* gfxCtx;
               void (*main)(struct GameState*);
               void (*destroy)(struct GameState*);
               void (*init)(struct GameState*);
               u32 size;
               Input input[4];
               char tha[0x10];
               GameAlloc alloc;
               u32 running;
               u32 frames;
               u32 unk_A0;
} GameState;
typedef struct {
                 GameState state;
                 void* staticSegment;
                 View view;
                 Sram sram;
                 u16 unk_1D4;
                 s16 coverAlpha;
                 s16 addAlpha;
                 u16 visibleDuration;
                 s16 ult;
                 s16 uls;
                 char unk_1E0;
                 u8 exit;
                 char unk_1E2[6];
} TitleContext;
typedef struct
{
                 GameState state;
                 void* staticSegment;
                 View view;
} SampleContext;
typedef struct {
               u8 byte0;
               u8 byte1;
               u8 byte2;
               u8 byte3;
} ElfMessage;
typedef struct GlobalContext {
                  GameState state;
                  s16 sceneNum;
                  u8 sceneConfig;
                  char unk_A7[0x9];
                  SceneCmd* unk_B0;
                  char unk_B4[0x4];
                  View view;
                  CameraContext cameraCtx;
                  SoundContext soundCtx;
                  LightingContext lightCtx;
                  s32 unk_7B8;
                  char unk7BC[0x4];
                  CollisionContext colCtx;
                  ActorContext actorCtx;
                  CutsceneContext csCtx;
                  char unk_1DB4[0x1C4];
                  u16 unk_1F78;
                  char unk_1F7A[0x15E];
                  MessageContext msgCtx;
                  InterfaceContext interfaceCtx;
                  PauseContext pauseCtx;
                  u16 unk_10A20;
                  char unk_10A22[0x2];
                  u16 unk_10A24;
                  u16 unk_10A26;
                  f32 unk_10A28;
                  f32 unk_10A2C;
                  f32 unk_10A30;
                  char unk_10A34[0x5];
                  u8 skyDisabled;
                  u8 sunMoonDisabled;
                  u8 gloomySky;
                  u8 unk_10A3C;
                  u8 unk_10A3D;
                  u16 unk_10A3E;
                  char unk_10A40[0x2];
                  u8 unk_10A42;
                  u8 unk_10A43;
                  u8 unk_10A44;
                  u8 unk_10A45;
                  u16 unk_10A46;
                  u16 unk_10A48;
                  char unk_10A4A[0x4];
                  s8 unk_10A4E;
                  s8 unk_10A4F;
                  s8 unk_10A50;
                  char unk_10A51[0x5F];
                  s16 unk_10AB0[6];
                  char unk_10ABC[0x8];
                  s16 unk_10AC4;
                  char unk_10AC6[0x6];
                  s16 unk_10ACC;
                  s16 unk_10ACE;
                  s16 unk_10AD0;
                  f32 unk_10AD4;
                  u8 nbLightSettings;
                  char unk_10AD9[0x3];
                  void* lightSettingsList;
                  char unk_10AE0[0x3];
                  u8 unk_10AE3;
                  char unk_10AE4[0x18];
                  f32 unk_10AFC;
                  u8 unk_10B00;
                  u8 gloomySkyEvent;
                  u8 unk_10B02;
                  u8 lightning;
                  u8 unk_10B04;
                  u8 unk_10B05;
                  u8 unk_10B06[4];
                  u8 unk_10B0A;
                  char unk_10B0B[0x7];
                  u8 unk_10B12[4];
                  u8 unk_10B16[4];
                  char unk_10B1A[0x6];
                  AnimationContext animationCtx;
                  ObjectContext objectCtx;
                  RoomContext roomCtx;
                  s16 unk_11D30[2];
                  u8 nbTransitionActors;
                  TransitionActorEntry* transitionActorList;
                  char unk_11D3C[0x1C];
                  void (*unk_11D58)(struct GlobalContext*, s32);
                  char unk_11D5C[0x4];
                  MtxF mf_11D60;
                  MtxF mf_11DA0;
                  char unk_11DE0[0x4];
                  u32 gameplayFrames;
                  u8 linkAgeOnLoad;
                  u8 unk_11DE9;
                  u8 curSpawn;
                  u8 nbSetupActors;
                  u8 nbRooms;
                  RomFile* roomList;
                  ActorEntry* linkActorEntry;
                  ActorEntry* setupActorList;
                  void* unk_11DFC;
                  EntranceEntry* setupEntranceList;
                  void* setupExitList;
                  Path* setupPathList;
                  ElfMessage* cUpElfMsgs;
                  char unk_11E10[0x4];
                  u8 skyboxId;
                  s8 sceneLoadFlag;
                  char unk_11E16[0x4];
                  s16 nextEntranceIndex;
                  char unk_11E1C[0x40];
                  s8 unk_11E5C;
                  s8 bombchuBowlingAmmo;
                  u8 fadeOutTransition;
                  char unk_11E5F[0x1];
                  SubGlobalContext11E60 sub_11E60;
                  char unk_120EC[0x304];
                  s32 unk_123F0;
                  char unk_123F4[0x27];
                  u8 unk_1241B;
                  char unk_1241C[0xF];
                  u8 unk_1242B;
                  Scene* loadedScene;
                  char unk_12430[0xE8];
} GlobalContext;
typedef struct {
                 GameState state;
                 char unk_A4[4];
                 View view;
} OpeningContext;
typedef enum {
    DPM_UNK = 0,
    DPM_PLAYER = 1,
    DPM_ENEMY = 2
} DynaPolyMoveFlag;
typedef struct LoadedParticleEntry {
                 Vec3f position;
                 Vec3f velocity;
                 Vec3f acceleration;
                 void(*update)(GlobalContext*, s32, struct LoadedParticleEntry*);
                 void(*draw)(GlobalContext*, s32, struct LoadedParticleEntry*);
                 f32 unk_2C;
                 f32 unk_30;
                 f32 unk_34;
                 u32 unk_38;
                 u32 unk_3C;
                 u16 unk_40[13];
                 u16 flags;
                 s16 life;
                 u8 priority;
                 u8 type;
} LoadedParticleEntry;
typedef struct {
               AnimationHeader* animation;
               f32 playbackSpeed;
               f32 unk_08;
               f32 frameCount;
               u8 unk_10;
               f32 transitionRate;
} struct_80034EC0_Entry;
typedef struct {
               u32 unk_00;
               u32(*init)(GlobalContext*, u32, LoadedParticleEntry*, void*);
} ParticleOverlayInfo;
typedef struct {
               u32 vromStart;
               u32 vromEnd;
               void* vramStart;
               void* vramEnd;
               void* loadedRamAddr;
               ParticleOverlayInfo* overlayInfo;
               u32 unk_18;
} ParticleOverlay;
typedef struct {
               LoadedParticleEntry* data_table;
               s32 searchIndex;
               s32 size;
} EffectTableInfo;
typedef struct {
               s8 scene;
               s8 spawn;
               u16 continueBgm : 1;
               u16 displayTitleCard : 1;
               u16 fadeInTransition : 7;
               u16 fadeOutTransition : 7;
} EntranceInfo;
typedef struct {
               void* loadedRamAddr;
               u32 vromStart;
               u32 vromEnd;
               void* vramStart;
               void* vramEnd;
               void* unk_14;
               void* init;
               void* destroy;
               void* unk_20;
               void* unk_24;
               s32 unk_28;
               u32 instanceSize;
} GameStateOverlay;
typedef struct PreNMIContext {
               GameState state;
               u32 timer;
               s32 unk_A8;
} PreNMIContext;
typedef struct {
               s8 chestFlag;
               u8 x, y;
} MapMarkPoint;
typedef struct {
               s8 markType;
               u8 count;
               MapMarkPoint points[12];
} MapMarkData;
typedef MapMarkData MapMarksData[3];
typedef struct DebugDispObject {
               Vec3f pos;
               Vec3s rot;
               Vec3f scale;
               Color_RGBA8 color;
               s16 type;
               struct DebugDispObject* next;
} DebugDispObject;
typedef struct {
               Vec3s colAbsMin;
               Vec3s colAbsMax;
               s16 nbVertices;
               void* vertexArray;
               s16 nbPolygons;
               void* polygonArray;
               void* polygonTypes;
               void* cameraData;
               s16 nbWaterBoxes;
               void* waterBoxes;
} CollisionHeader;
typedef enum {
    MTXMODE_NEW,
    MTXMODE_APPLY
} MatrixMode;
typedef struct FaultClient {
    struct FaultClient* next;
    u32 callback;
    u32 param1;
    u32 param2;
} FaultClient;
typedef struct FaultAddrConvClient {
    struct FaultAddrConvClient* next;
    u32 callback;
    u32 param;
} FaultAddrConvClient;
typedef struct {
    u32 (*callback)(u32, u32);
    u32 param0;
    u32 param1;
    u32 ret;
    OSMesgQueue* queue;
    OSMesg msg;
} FaultClientContext;
typedef struct FaultThreadStruct {
    OSThread thread;
    u8 unk_1B0[0x600];
    OSMesgQueue queue;
    OSMesg msg;
    u8 exitDebugger;
    u8 msgId;
    u8 faultHandlerEnabled;
    u8 faultActive;
    OSThread* faultedThread;
    void(*padCallback)(Input*);
    FaultClient* clients;
    FaultAddrConvClient* addrConvClients;
    u8 unk_7E0[4];
    Input padInput;
    u16 colors[36];
    void* fb;
    u32 currClientThreadSp;
    u8 unk_84C[4];
} FaultThreadStruct;
typedef struct {
    u16* fb;
    u16 w;
    u16 h;
    u16 yStart;
    u16 yEnd;
    u16 xStart;
    u16 xEnd;
    u16 foreColor;
    u16 backColor;
    u16 cursorX;
    u16 cursorY;
    u32* fontData;
    u8 charW;
    u8 charH;
    s8 charWPad;
    s8 charHPad;
    u16 printColors[10];
    u8 escCode;
    u8 osSyncPrintfEnabled;
    void(*inputCallback)();
} FaultDrawer;
typedef struct GfxPrint {
               struct GfxPrint*(*callback)(struct GfxPrint*, const char*, size_t);
               Gfx* dlist;
               u16 posX;
               u16 posY;
               u16 baseX;
               u8 baseY;
               u8 flag;
               Color_RGBA8 color;
} GfxPrint;
typedef enum {
    GFXPRINT_FLAG1 = 1,
    GFXPRINT_USE_RGBA16 = 2,
    GFXPRINT_FLAG4 = 4,
    GFXPRINT_UPDATE_MODE = 8,
    GFXPRINT_FLAG64 = 0x40,
    GFXPRINT_OPEN = 0x80
} GfxPrintFlag;
typedef struct StackEntry {
               struct StackEntry* next;
               struct StackEntry* prev;
               u32 head;
               u32 tail;
               u32 initValue;
               s32 minSpace;
               const char* name;
} StackEntry;
typedef enum {
    STACK_STATUS_OK = 0,
    STACK_STATUS_WARNING = 1,
    STACK_STATUS_OVERFLOW = 2
} StackStatus;
typedef struct {
               u32 magic;
               u32 get;
               u8 unk_08[0x14-0x08];
               u32 put;
               u8 unk_18[0x20-0x18];
               u8 data[0x10000-0x20];
} ISVDbg;
typedef struct {
    char name[0x18];
    u32 mediaFormat;
    union {
        struct {
            u16 cartId;
            u8 countryCode;
            u8 version;
        };
        u32 regionInfo;
    };
} LocaleCartInfo;
typedef struct {
    char magic[4];
    u32 decSize;
    u32 compInfoOffset;
    u32 uncompDataOffset;
    u32 data[1];
} Yaz0Header;
typedef struct {
    short type;
    char misc[30];
} OSScMsg;
typedef struct IrqMgrClient {
    struct IrqMgrClient* prev;
    OSMesgQueue* queue;
} IrqMgrClient;
typedef struct {
                OSScMsg retraceMsg;
                OSScMsg prenmiMsg;
                OSScMsg nmiMsg;
                OSMesgQueue queue;
                OSMesg msgBuf[8];
                OSThread thread;
                IrqMgrClient* clients;
                u8 resetStatus;
                OSTime resetTime;
                OSTimer timer;
                OSTime retraceTime;
} IrqMgr;
struct ArenaNode;
typedef struct Arena {
               struct ArenaNode* head;
               void* start;
               OSMesgQueue lock;
               u8 unk_20;
               u8 isInit;
               u8 flag;
} Arena;
typedef struct ArenaNode {
               s16 magic;
               s16 isFree;
               u32 size;
               struct ArenaNode* next;
               struct ArenaNode* prev;
               const char* filename;
               s32 line;
               OSId threadId;
               Arena* arena;
               OSTime time;
               u8 unk_28[0x30-0x28];
} ArenaNode;
typedef struct OverlayRelocationSection {
               u32 textSize;
               u32 dataSize;
               u32 rodataSize;
               u32 bssSize;
               u32 nRelocations;
               u32 relocations[1];
} OverlayRelocationSection;
typedef struct {
               void* loadedRamAddr;
               u32 vromStart;
               u32 vromEnd;
               u8* vramStart;
               u8* vramEnd;
               u32 off;
               const char* name;
} KaleidoManagerOvl;
typedef struct ListAlloc {
               struct ListAlloc* prev;
               struct ListAlloc* next;
} ListAlloc;
typedef struct {
               u32 resetting;
               u32 resetCount;
               OSTime duration;
               OSTime resetTime;
} PreNmiBuff;
typedef struct {
               s16 unk_00;
               s16 unk_02;
               s16 unk_04;
} SubQuakeRequest14;
typedef struct {
               s16 randIdx;
               s16 countdownMax;
               Camera* cam;
               u32 callbackIdx;
               s16 y;
               s16 x;
               s16 zoom;
               s16 rotZ;
               SubQuakeRequest14 unk_14;
               s16 speed;
               s16 unk_1C;
               s16 countdown;
               s16 camPtrIdx;
} QuakeRequest;
typedef struct {
               Vec3f vec1;
               Vec3f vec2;
               s16 rotZ;
               s16 unk_1A;
               s16 zoom;
} ShakeInfo;
typedef struct {
               Vec3f vec1;
               Vec3f vec2;
               s16 rotZ;
               s16 unk_1A;
               s16 zoom;
               f32 unk_20;
} UnkQuakeCalcStruct;
typedef struct {
               u32 idx;
               void* ptr;
} UCodeInfo;
typedef struct {
               u32 segments[(16)];
               u32 dlStack[18];
               u32 dlDepth;
               u32 dlCnt;
               u32 vtxCnt;
               u32 spvtxCnt;
               u32 tri1Cnt;
               u32 tri2Cnt;
               u32 quadCnt;
               u32 lineCnt;
               u32 loaducodeCnt;
               u32 pipeSyncRequired;
               u32 tileSyncRequired;
               u32 loadSyncRequired;
               u32 syncErr;
               u32 enableLog;
               u32 ucodeInfoIdx;
               u32 ucodeInfoCount;
               UCodeInfo* ucodeInfo;
               u32 modeH;
               u32 modeL;
               u32 geometryMode;
} UCodeDisas;
typedef struct {
               u16* fb1;
               u16* swapbuffer;
               OSViMode* viMode;
               u32 features;
               u8 unk_10;
               u8 updateRate;
               u8 updateRate2;
               u8 unk_13;
               f32 xScale;
               f32 yScale;
} CfbInfo;
float fabsf(float f);
#pragma intrinsic(fabsf)
float sqrtf(float f);
#pragma intrinsic(sqrtf)
void cleararena(void);
void bootproc(void);
void Main_ThreadEntry(void* arg0);
void Idle_ThreadEntry(void* a0);
void ViConfig_UpdateVi(u32 arg0);
void ViConfig_UpdateBlack();
s32 DmaMgr_CompareName(const char* name1, const char* name2);
s32 DmaMgr_DMARomToRam(u32 rom, u32 ram, u32 size);
s32 DmaMgr_DmaCallback0(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction);
void DmaMgr_DmaCallback1(u32 ram, u32 rom, u32 size);
void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc);
const char* DmaMgr_GetFileNameImpl(u32 vrom);
const char* DmaMgr_GetFileName(u32 vrom);
void DmaMgr_ProcessMsg(DmaRequest* req);
void DmaMgr_ThreadEntry(void* arg0);
s32 DmaMgr_SendRequestImpl(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk, OSMesgQueue* queue, OSMesg msg);
s32 DmaMgr_SendRequest0(u32 ram, u32 vrom, u32 size);
void DmaMgr_Start();
s32 DmaMgr_SendRequest2(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk5, OSMesgQueue* queue, OSMesg msg,
                        const char* file, s32 line);
s32 DmaMgr_SendRequest1(void* ram0, u32 vrom, u32 size, const char* file, s32 line);
void* Yaz0_FirstDMA();
void* Yaz0_NextDMA(void* curSrcPos);
void Yaz0_DecompressImpl(Yaz0Header* hdr, u8* dst);
void Yaz0_Decompress(u32 romStart, void* dst, u32 size);
void Locale_Init();
void Locale_ResetRegion();
u32 func_80001F48();
u32 func_80001F8C();
u32 Locale_IsRegionNative();
void __assert(const char* exp, const char* file, s32 line);
void isPrintfInit();
void osSyncPrintfUnused(const char* fmt, ...);
void osSyncPrintf(const char* fmt, ...);
void rmonPrintf(const char* fmt, ...);
u32 is_proutSyncPrintf(void* arg0, const char* str, s32 count);
void func_80002384(const char* exp, const char* file, u32 line);
OSPiHandle* osDriveRomInit();
void Yaz0_Old_DecompressImpl(Yaz0Header* hdr, u8* dst);
void StackCheck_Init(StackEntry* entry, void* stackTop, void* stackBottom, u32 initValue, s32 minSpace,
                     const char* name);
void StackCheck_Cleanup(StackEntry* entry);
StackStatus StackCheck_GetState(StackEntry* entry);
u32 StackCheck_CheckAll();
u32 StackCheck_Check(StackEntry* entry);
float LogUtils_CheckFloatRange(const char* exp, s32 arg1, const char* var1Name, float var1, const char* var2Name,
                               float var2, const char* var3Name, float var3);
s32 LogUtils_CheckIntRange(const char* exp, s32 arg1, const char* var1Name, s32 var1, const char* var2Name, s32 var2,
                           const char* var3Name, s32 var3);
void LogUtils_LogHexDump(void* ptr, s32 size0);
void LogUtils_LogPointer(s32 value, u32 max, void* ptr, const char* name, const char* file, s32 line);
void LogUtils_CheckBoundary(const char* name, s32 value, s32 unk, const char* file, s32 line);
void LogUtils_CheckNullPointer(const char* exp, void* ptr, const char* file, s32 line);
void LogUtils_CheckValidPointer(const char* exp, void* ptr0, const char* file, s32 line);
void LogUtils_LogThreadId(const char* name, s32 line);
void LogUtils_HungupThread(const char* name, s32 line);
void LogUtils_ResetHungup();
char* proutSprintf(char* dst, const char* fmt, size_t size);
s32 vsprintf(char* dst, const char* fmt, va_list args);
s32 sprintf(char* dst, const char* fmt, ...);
void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
s32 osSendMesg(OSMesgQueue* mq, OSMesg mesg, s32 flag);
void osStopThread(OSThread* thread);
void osViExtendVStart(u32 arg0);
s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flag);
void __createSpeedParam(void);
void __osInitialize_common(void);
void __osInitialize_autodetect();
void __osExceptionPreamble();
void __osEnqueueAndYield(OSThread**);
void __osEnqueueThread(OSThread**, OSThread*);
OSThread* __osPopThread(OSThread**);
void __osDispatchThread();
void __osCleanupThread(void);
void __osDequeueThread(OSThread** queue, OSThread* thread);
void osDestroyThread(OSThread* thread);
void bzero(void* __s, u32 __n);
void osCreateThread(OSThread* thread, OSId id, void (*entry)(void*), void* arg, void* sp, OSPri pri);
void __osSetSR(u32);
u32 __osGetSR();
void osWritebackDCache(void* vaddr, s32 nbytes);
void* osViGetNextFramebuffer();
void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt);
void __osDevMgrMain(void* arg);
s32 __osPiRawStartDma(s32 dir, u32 cart_addr, void* dram_addr, size_t size);
u32 osVirtualToPhysical(void* vaddr);
void osViBlack(u8 active);
s32 __osSiRawReadIo(void* a0, u32* a1);
OSId osGetThreadId(OSThread* thread);
OSIntMask osSetIntMask(OSIntMask);
void osViSetMode(OSViMode* mode);
u32 __osProbeTLB(void*);
u32 osGetMemSize(void);
void osSetEventMesg(OSEvent e, OSMesgQueue* mq, OSMesg msg);
s32 _Printf(char* (*pfn)(char*, const char*, size_t), char* arg, const char* fmt, va_list ap);
void osUnmapTLBAll(void);
s32 osEPiStartDma(OSPiHandle* handle, OSIoMesg* mb, s32 direction);
const u8* strchr(const u8* str, s32 ch);
size_t strlen(const u8* str);
void* memcpy(void* dst, const void* src, size_t size);
void osInvalICache(void* vaddr, s32 nbytes);
void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, s32 count);
void osInvalDCache(void* vaddr, s32 nbytes);
u32 __osSiDeviceBusy();
void osSetThreadPri(OSThread* thread, OSPri pri);
OSPri osGetThreadPri(OSThread* thread);
s32 __osEPiRawReadIo(OSPiHandle* handle, u32 devAddr, u32* data);
void osViSwapBuffer(void* vaddr);
s32 __osEPiRawStartDma(OSPiHandle* handle, s32 direction, u32 cartAddr, void* dramAddr, size_t size);
u32 bcmp(void* __sl, void* __s2, u32 __n);
OSTime osGetTime(void);
void __osTimerServicesInit();
void __osTimerInterrupt();
void __osSetTimerIntr(OSTime tim);
OSTime __osInsertTimer(OSTimer* a0);
u32 osGetCount(void);
void __osSetGlobalIntMask(u32 mask);
void __osSetCompare(u32);
void* bcopy(void* __src, void* __dest, u32 __n);
void __osResetGlobalIntMask(u32 mask);
s32 __osDisableInt(void);
void __osRestoreInt(s32);
void __osViInit();
void __osViSwapContext();
OSMesgQueue* osPiGetCmdQueue();
s32 osEPiReadIo(OSPiHandle* handle, u32 devAddr, u32* data);
void osViSetSpecialFeatures(u32 func);
OSPiHandle* osCartRomInit();
void __osSetFpcCsr(u32);
u32 __osGetFpcCsr();
s32 osEPiWriteIo(OSPiHandle* handle, u32 devAddr, u32 data);
void osMapTLBRdb(void);
u32 __osGetCause();
s32 __osEPiRawWriteIo(OSPiHandle* handle, u32 devAddr, u32 data);
void osCreateViManager(OSPri pri);
void viMgrMain(void* vargs);
OSViContext* __osViGetCurrentContext();
void osStartThread(OSThread* thread);
void osViSetYScale(float scale);
void osViSetXScale(f32 value);
void __osSetHWIntrRoutine(s32 idx, OSMesgQueue* queue, OSMesg msg);
void __osGetHWIntrRoutine(s32 idx, OSMesgQueue** outQueue, OSMesg* outMsg);
void __osSetWatchLo(u32);
Actor* Item_DropCollectible(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
Actor* Item_DropCollectible2(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
void Item_DropCollectibleRandom(GlobalContext* globalCtx, Actor* fromActor, Vec3f* spawnPos, s16 params);
void func_80024F0C(s32);
void func_80026400(GlobalContext*, Color_RGBA8*, u8, s16);
void func_80026860(GlobalContext*, Color_RGBA8*, u8, s16);
GlobalContext* func_80026B00(void);
void Effect_SS_ResetEntry(LoadedParticleEntry* particle);
void func_800286CC(GlobalContext*, Vec3f*, Vec3f*, Vec3f*, s16, s16);
void func_80028B74(GlobalContext*, Vec3f*, void*, void*, Color_RGB8*, Color_RGB8*);
void Effect_SpawnFragment(GlobalContext* globalCtx, Vec3f* burstDepthY, Vec3f* burstDepthX, Vec3f* burstOrigin,
                          s16 gravityInfluence, s16 u0, s16 rotSpeed, s16 burstVel, u8 u1, s16 scale, u8 u2, s16 jitter,
                          s32 duration, s16 u3, s16 objNumber, u32 dList);
void func_8002A65C(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, u32 arg3, u32 arg4);
void func_8002A6B8(GlobalContext* globalCtx, Vec3f* pos, Vec3f* arg2, Vec3f* arg3, u32 arg4, s32 arg5, u32 arg6,
                   u32 arg7, u32 arg8, u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13, u32 arg14, u32 arg15);
void Overlay_LoadGameState(GameStateOverlay* overlayEntry);
void Overlay_FreeGameState(GameStateOverlay* overlayEntry);
void ActorShape_Init(ActorShape* shape, f32 arg1, void* shadowDrawFunc, f32 arg3);
void ActorShadow_DrawFunc_Circle(Actor* actor, LightMapper* lightMapper, GlobalContext* globalCtx);
void ActorShadow_DrawFunc_WhiteCircle(Actor* actor, LightMapper* lightMapper, GlobalContext* globalCtx);
void ActorShadow_DrawFunc_Squiggly(Actor* actor, LightMapper* lightMapper, GlobalContext* globalCtx);
void ActorShadow_DrawFunc_Teardrop(Actor* actor, LightMapper* lightMapper, GlobalContext* globalCtx);
void func_8002BDB0(Actor* actor, s32 arg1, s32 arg2, void* arg3, s32 arg4, void* arg5);
void func_8002C124(TargetContext* targetCtx, GlobalContext* globalCtx);
s32 Flags_GetSwitch(GlobalContext* globalCtx, s32 flag);
void Flags_SetSwitch(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetSwitch(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetUnknown(GlobalContext* globalCtx, s32 flag);
void Flags_SetUnknown(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetUnknown(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetTreasure(GlobalContext* globalCtx, s32 flag);
void Flags_SetTreasure(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetClear(GlobalContext* globalCtx, s32 flag);
void Flags_SetClear(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetClear(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetTempClear(GlobalContext* globalCtx, s32 flag);
void Flags_SetTempClear(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetTempClear(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetCollectible(GlobalContext* globalCtx, s32 flag);
void Flags_SetCollectible(GlobalContext* globalCtx, s32 flag);
void TitleCard_InitBossName(GlobalContext* globalCtx, TitleCardContext* titleCtx, u32 texture, s16 arg3, s16 arg4,
                            u8 arg5, u8 arg6);
void TitleCard_InitPlaceName(GlobalContext* globalCtx, TitleCardContext* titleCtx, u32 texture, s32 arg3, s32 arg4,
                             s32 arg5, s32 arg6, s32 arg7);
s32 func_8002D53C(GlobalContext* globalCtx, TitleCardContext* titleCtx);
void Actor_Kill(Actor* actor);
void Actor_SetHeight(Actor* actor, f32 offset);
void Actor_SetScale(Actor* actor, f32 scale);
void Actor_SetObjectDependency(GlobalContext* globalCtx, Actor* actor);
void func_8002D7EC(Actor* actor);
void func_8002D868(Actor* actor);
void Actor_MoveForward(Actor* actor);
void func_8002D908(Actor* actor);
void func_8002D97C(Actor* actor);
void func_8002D9A4(Actor* actor, f32 arg1);
s16 func_8002DA78(Actor* actorA, Actor* actorB);
s16 func_8002DAC0(Actor* actor, Vec3f* arg1);
f32 func_8002DB48(Actor* actorA, Actor* actorB);
s16 func_8002DAE0(Actor* actorA, Actor* actorB);
s16 func_8002DB28(Actor* actor, Vec3f* arg1);
f32 func_8002DB8C(Actor* actorA, Actor* actorB);
f32 func_8002DBB0(Actor* actor, Vec3f* arg1);
void func_8002DBD0(Actor* actor, Vec3f* result, Vec3f* arg2);
f32 Actor_HeightDiff(Actor* actorA, Actor* actorB);
f32 func_8002DC84(Player* player);
f32 func_8002DCE4(Player* player);
s32 func_8002DD6C(Player* player);
s32 func_8002DD78(Player* player);
s32 func_8002DDE4(GlobalContext* globalCtx);
s32 func_8002DDF4(GlobalContext* globalCtx);
void func_8002DE04(GlobalContext* globalCtx, Actor* actorA, Actor* actorB);
void func_8002DE74(GlobalContext* globalCtx, Player* player);
void func_8002DECC(GlobalContext* globalCtx, Player* player, Actor* actor);
s32 func_8002DEEC(Player* player);
void func_8002DF18(GlobalContext* globalCtx, ActorContext* actorCtx);
u32 func_8002DF38(GlobalContext* globalCtx, Actor* actor, u8 newAction);
s32 func_8002DF54(GlobalContext* globalCtx, Actor* actor, u8 arg2);
void func_8002DF90(DynaPolyActor* dynaActor);
void func_8002DFA4(DynaPolyActor* dynaActor, f32 arg1, s16 arg2);
s32 func_8002DFC8(Actor* actor, s16 arg1, GlobalContext* globalCtx);
s32 func_8002E084(Actor* actor, s16 arg1);
s32 func_8002E12C(Actor* actor, f32 arg1, s16 arg2);
s32 func_8002E1A8(Actor* actorA, Actor* actorB, f32 arg2, s16 arg3);
void func_8002E4B4(GlobalContext* globalCtx, Actor* actor, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
Hilite* func_8002EABC(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx);
Hilite* func_8002EB44(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx);
void func_8002EBCC(Actor* actor, GlobalContext* globalCtx, s32 flag);
void func_8002ED80(Actor* actor, GlobalContext* globalCtx, s32 flag);
PosRot* func_8002EEE4(PosRot* arg0, Actor* actor);
PosRot* func_8002EF14(PosRot* arg0, Actor* actor);
PosRot* func_8002EF44(PosRot* arg0, Actor* actor);
s32 func_8002F0C8(Actor* actor, Player* player, s32 arg2);
u32 func_8002F194(Actor* actor, GlobalContext* globalCtx);
s32 func_8002F1C4(Actor* actor, GlobalContext* globalCtx, f32 arg2, f32 arg3, u32 arg4);
s32 func_8002F298(Actor* actor, GlobalContext* globalCtx, f32 arg2, u32 arg3);
s32 func_8002F2CC(Actor* actor, GlobalContext* globalCtx, f32 arg2);
s32 func_8002F2F4(Actor* actor, GlobalContext* globalCtx);
u32 func_8002F334(Actor* actor, GlobalContext* globalCtx);
s8 func_8002F368(GlobalContext* globalCtx);
void func_8002F374(GlobalContext* globalCtx, Actor* actor, s16* arg2, s16* arg3);
u32 func_8002F410(Actor* actor, GlobalContext* globalCtx);
s32 func_8002F434(Actor* actor, GlobalContext* globalCtx, s32 getItemId, f32 xzRange, f32 yRange);
void func_8002F554(Actor* actor, GlobalContext* globalCtx, s32 getItemId);
void func_8002F580(Actor* actor, GlobalContext* globalCtx);
u32 func_8002F5A0(Actor* actor, GlobalContext* globalCtx);
void func_8002F5C4(Actor* actorA, Actor* actorB, GlobalContext* globalCtx);
void func_8002F5F0(Actor* actor, GlobalContext* globalCtx);
u32 func_8002F618(GlobalContext* globalCtx, Actor* actor);
u32 func_8002F63C(GlobalContext* globalCtx, Actor* actor, s32 arg2);
u32 func_8002F674(GlobalContext* globalCtx, Actor* actor);
void func_8002F698(GlobalContext* globalCtx, u32 arg1, f32 arg2, s16 arg3, f32 arg4, u32 arg5, u32 arg6);
void func_8002F6D4(GlobalContext* globalCtx, u32 arg1, f32 arg2, s16 arg3, f32 arg4, u32 arg5);
void func_8002F71C(GlobalContext* globalCtx, u32 arg1, f32 arg2, s16 arg3, f32 arg4);
void func_8002F758(GlobalContext* globalCtx, u32 arg1, f32 arg2, s16 arg3, f32 arg4, u32 arg5);
void func_8002F7A0(GlobalContext* globalCtx, u32 arg1, f32 arg2, s16 arg3, f32 arg4);
void func_8002F7DC(Actor* actor, u16 sfxId);
void Audio_PlayActorSound2(Actor* actor, u16 sfxId);
void func_8002F850(GlobalContext* globalCtx, Actor* actor);
void func_8002F8F0(Actor* actor, u16 sfxId);
void func_8002F91C(Actor* actor, u16 sfxId);
void func_8002F948(Actor* actor, u16 sfxId);
void func_8002F974(Actor* actor, u16 sfxId);
void func_8002F994(Actor* actor, s32 sfxId);
s32 func_8002F9EC(GlobalContext* globalCtx, Actor* actor, s32 arg2, s32 arg3, s32 arg4);
void func_800304B0(GlobalContext* globalCtx);
void func_800304DC(GlobalContext* globalCtx, ActorContext* actorCtx, ActorEntry* actorEntry);
void Actor_UpdateAll(GlobalContext* globalCtx, ActorContext* actorCtx);
s32 func_800314D4(GlobalContext* globalCtx, Actor* actorB, Vec3f* arg2, f32 arg3);
void func_80031B14(GlobalContext* globalCtx, ActorContext* actorCtx);
Actor* Actor_Spawn(ActorContext* actorCtx, GlobalContext* globalCtx, s16 actorId, f32 posX, f32 posY, f32 posZ,
                   s16 rotX, s16 rotY, s16 rotZ, s16 params);
Actor* Actor_SpawnAttached(ActorContext* actorCtx, Actor* attachedTo, GlobalContext* globalCtx, s16 actorId, f32 posX,
                           f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, s16 params);
void Actor_SpawnTransitionActors(GlobalContext* globalCtx, ActorContext* actorCtx);
Actor* Actor_SpawnEntry(ActorContext* actorCtx, ActorEntry* actorEntry, GlobalContext* globalCtx);
Actor* Actor_Delete(ActorContext* actorCtx, Actor* actor, GlobalContext* globalCtx);
Actor* func_80032AF0(GlobalContext* globalCtx, ActorContext* actorCtx, Actor** actorPtr, Player* player);
Actor* Actor_Find(ActorContext* actorCtx, s32 actorId, s32 actorType);
void func_80032C7C(GlobalContext* globalCtx, Actor* actor);
void func_80033260(GlobalContext* globalCtx, Actor* actor, Vec3f* arg2, f32 arg3, s32 arg4, f32 arg5, s16 arg6,
                   s16 arg7, u8 arg8);
void func_80033480(GlobalContext* globalCtx, Vec3f* arg1, f32 arg2, s32 arg3, s16 arg4, s16 arg5, u8 arg6);
Actor* func_80033640(GlobalContext* globalCtx, Collider* collider);
Actor* func_80033684(GlobalContext* globalCtx, Actor* explosiveActor);
void Actor_ChangeType(GlobalContext* globalCtx, ActorContext* actorCtx, Actor* actor, u8 actorType);
void Actor_SetTextWithPrefix(GlobalContext* globalCtx, Actor* actor, s16 textIdLower);
s16 func_800339B8(Actor* actor, GlobalContext* globalCtx, f32 arg2, s16 arg3);
s32 func_80033A84(GlobalContext* globalCtx, Actor* actor);
s32 func_80033AB8(GlobalContext* globalCtx, Actor* actor);
f32 func_80033AEC(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_80033C30(Vec3f* arg0, Vec3f* arg1, u8 alpha, GlobalContext* globalCtx);
void func_80033DB8(GlobalContext* globalCtx, s16 arg1, s16 arg2);
void func_80033E1C(GlobalContext* globalCtx, s16 arg1, s16 arg2, s16 arg3);
void func_80033E88(Actor* actor, GlobalContext* globalCtx, s16 arg2, s16 arg3);
f32 Math_Rand_ZeroFloat(f32 f);
f32 Math_Rand_CenteredFloat(f32 f);
void func_80033F54(GlobalContext* globalCtx, s32 arg1, s32 arg2);
void func_8003424C(GlobalContext* globalCtx, Vec3f* arg1);
void func_8003426C(Actor* actor, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
Hilite* func_800342EC(Vec3f* object, GlobalContext* globalCtx);
Hilite* func_8003435C(Vec3f* object, GlobalContext* globalCtx);
s32 func_800343CC(GlobalContext* globalCtx, Actor* actor, s16* arg2, f32 arg3, u16 (*unkFunc1)(GlobalContext*, Actor*),
                  s16 (*unkFunc2)(GlobalContext*, Actor*));
s16 func_800347E8(s16 arg0);
void func_80034BA0(GlobalContext* globalCtx, SkelAnime* skelAnime, SkelAnime_LimbUpdateMatrix2 unkFunc1,
                   SkelAnime_LimbAppendDlist2 unkFunc2, Actor* actor, s16 alpha);
void func_80034CC4(GlobalContext* globalCtx, SkelAnime* skelAnime, SkelAnime_LimbUpdateMatrix2 unkFunc1,
                   SkelAnime_LimbAppendDlist2 unkFunc2, Actor* actor, s16 alpha);
void func_80034EC0(SkelAnime* skelAnime, struct_80034EC0_Entry* arg1, s32 arg2);
void Actor_Noop(Actor* actor, GlobalContext* globalCtx);
void Gfx_DrawDListOpa(GlobalContext* globalCtx, u32 dlist);
void Gfx_DrawDListXlu(GlobalContext* globalCtx, u32 dlist);
Actor* Actor_FindNearby(GlobalContext* globalCtx, Actor* refActor, s16 actorId, u8 actorType, f32 range);
s32 func_800354B4(GlobalContext* globalCtx, Actor* actor, f32 range, s16 arg3, s16 arg4, s16 arg5);
void func_8003555C(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3);
void func_800355B8(GlobalContext* globalCtx, Vec3f* arg1);
u8 func_800355E4(GlobalContext* globalCtx, ColliderCylinderInit* colCylinderInit);
u8 Actor_ApplyDamage(Actor* actor);
void func_80035650(Actor* actor, ColliderBody* colBody, s32 freezeFlag);
void func_8003573C(Actor* actor, ColliderBody* colBody, s32 freezeFlag);
void func_80035844(Vec3f* arg0, Vec3f* arg1, s16* arg2, s32 arg3);
void func_800359B8(Actor* actor, s16 arg1, Vec3s* arg2);
s32 Flags_GetEventChkInf(s32 flag);
void Flags_SetEventChkInf(s32 flag);
s32 Flags_GetInfTable(s32 flag);
void Flags_SetInfTable(s32 flag);
u16 func_80037C30(GlobalContext* globalCtx, s16 arg1);
s32 func_80037D98(GlobalContext* globalCtx, Actor* actor, s16 arg2, s32* arg3);
s32 func_80038290(GlobalContext* globalCtx, Actor* actor, Vec3s* arg2, Vec3s* arg3, Vec3f arg4);
void ActorOverlayTable_LogPrint(void);
void ActorOverlayTable_Init(void);
void ActorOverlayTable_Cleanup(void);
void func_80038A28(CollisionPoly*, f32, f32, f32, MtxF*);
f32 func_8003C8EC(GlobalContext*, CollisionContext*, CollisionPoly**, Vec3f*);
f32 func_8003CA0C(GlobalContext*, CollisionContext*, CollisionPoly**, u32*, Actor*, Vec3f*);
f32 func_8003CCA4(CollisionContext*, CollisionPoly**, s32*, Vec3f*);
s32 func_8003D52C(CollisionContext*, Vec3f*, Vec3f*, Vec3f*, f32, CollisionPoly**, u32*, Actor*, f32);
s32 func_8003D594(CollisionContext*, Vec3f*, Vec3f*, Vec3f*, f32, CollisionPoly**, u32*, Actor*, f32);
s32 func_8003D7A0(CollisionContext*, f32*, Vec3f*, f32, void*, u32*, Actor*);
s32 func_8003DE84(CollisionContext*, Vec3f*, Vec3f*, Vec3f*, CollisionPoly**, u32, u32, u32, u32, u32*);
s32 func_8003DF10(CollisionContext*, Vec3f*, Vec3f*, Vec3f*, CollisionPoly**, u32, u32, u32, u32, u32*, Actor*);
void func_8003EBF8(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, u32 dynaPolyId);
void func_8003EC50(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, u32 dynaPolyId);
u32 DynaPolyInfo_RegisterActor(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, Actor* actor, u32 arg3);
DynaPolyActor* DynaPolyInfo_GetActor(CollisionContext* colCtx, u32 dynaPolyId);
void DynaPolyInfo_Free(GlobalContext* globalCtx, DynaCollisionContext* dynaColCtx, u32 dynaPolyId);
void DynaPolyInfo_Alloc(u32 collision, void* collisionPtr);
s32 func_8004213C(GlobalContext*, CollisionContext*, f32, f32, f32*, void*);
s32 func_800427B4(CollisionPoly*, CollisionPoly*, s32, s32, Vec3f*);
void DynaPolyInfo_SetActorMove(DynaPolyActor* actor, DynaPolyMoveFlag flags);
void func_800434A0(DynaPolyActor* dynaActor);
void func_800434A8(DynaPolyActor* actor);
void func_80043538(DynaPolyActor* actor);
f32 func_800437F0(f32, f32);
s16 func_8005A970(u32 gl790);
s16 func_8005A9F4(Camera* camera);
s32 CollisionBtlTbl_Get(s32 index);
s32 func_8005B6A0(GlobalContext* globalCtx, Collider* collision);
s32 func_8005B6EC(GlobalContext* globalCtx, Collider* collision, Actor* actor, ColliderBodyInfo* src);
s32 func_8005B72C(GlobalContext* globalCtx, Collider* collision, Actor* actor, ColliderBodyInfo* src);
void func_8005B76C(GlobalContext* globalCtx, Collider* collision);
void func_8005B784(GlobalContext* globalCtx, Collider* collision);
void func_8005B79C(GlobalContext* globalCtx, Collider* collision);
s32 func_8005B7E4(GlobalContext* globalCtx, ColliderTouch* touch);
void func_8005B818(GlobalContext* globalCtx, ColliderBody* body);
s32 func_8005B850(GlobalContext* globalCtx, ColliderBump* bump);
s32 func_8005B904(GlobalContext* globalCtx, ColliderBody* body);
s32 func_8005B93C(GlobalContext* globalCtx, ColliderBody* colliderBody, ColliderBodyInfoInner* bodyFlags);
void func_8005B9B0(GlobalContext* globalCtx, ColliderBody* body);
void func_8005B9E8(GlobalContext* globalCtx, ColliderBody* body);
s32 func_8005BA74(s32, s32);
void func_8005C050(GlobalContext* globalCtx, Collider* collision, Actor* actor, s32 arg3, s32 arg4);
s32 func_8005C318(GlobalContext* globalCtx, ColliderDimensions* dim);
s32 func_8005C328(GlobalContext* globalCtx, ColliderDimensions* dest, ColliderDimensions* src);
s32 ActorCollider_AllocCylinder(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 ActorCollider_FreeCylinder(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 func_8005C3F4(GlobalContext* globalCtx, ColliderCylinderMain* collision, ColliderCylinderInit* arg2);
s32 ActorCollider_InitCylinder(GlobalContext* globalCtx, ColliderCylinderMain* collision, Actor* actor,
                               ColliderCylinderInit* src);
s32 func_8005C508(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 func_8005C540(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 func_8005C578(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 func_8005C5F8(s32, s32);
s32 func_8005CEB4(GlobalContext* globalCtx, ColliderDimensions* dim);
s32 func_8005D018(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 func_8005D060(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 func_8005D0A8(GlobalContext* globalCtx, ColliderCylinderMain* collision, Actor* actor, ColliderCylinderInit* src);
s32 func_8005D104(GlobalContext* globalCtx, ColliderCylinderMain* collision, Actor* actor, ColliderCylinderInit* src);
s32 func_8005D160(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 func_8005D1A8(GlobalContext* globalCtx, ColliderCylinderMain* collision);
s32 func_8005D1E0(GlobalContext* globalCtx, ColliderCylinderMain* collision);
void func_8005D400(s32, s32);
s32 Actor_CollisionCheck_SetAT(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups,
                               ColliderCylinderMain* collision);
s32 Actor_CollisionCheck_SetAC(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups,
                               ColliderCylinderMain* collision);
s32 Actor_CollisionCheck_SetOT(GlobalContext* globalCtx, SubGlobalContext11E60* simpleBodyGroups,
                               ColliderCylinderMain* collision);
void func_80061ED4(SubActorStruct98* sub98, ActorDamageChart* damageChart, Sub98Init4* sub98Init);
void func_80061EFC(SubActorStruct98* sub98, ActorDamageChart* damageChart, Sub98Init4* sub98Init);
void ActorCollider_Cylinder_Update(Actor* actor, ColliderCylinderMain* collision);
void func_80062D60(GlobalContext*, Vec3f*);
s32 func_80062ECC(f32, f32, f32, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void SaveContext_Init(void);
void func_8006375C(s32 arg0, s32 arg1, float* d_80855320);
void DebugDisplay_Init(void);
DebugDispObject* DebugDisplay_AddObject(f32 posX, f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, f32 scaleX,
                                        f32 scaleY, f32 scaleZ, u8 red, u8 green, u8 blue, u8 alpha, s16 type,
                                        GraphicsContext* gfxCtx);
void DebugDisplay_DrawObjects(GlobalContext* globalCtx);
void func_8006450C(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064534(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064558(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_800645A0(GlobalContext* globalCtx, CutsceneContext* csCtx);
void Cutscene_HandleEntranceTriggers(GlobalContext* globalCtx);
void Cutscene_HandleConditionalTriggers(GlobalContext* globalCtx);
void Cutscene_SetSegment(GlobalContext* globalCtx, u32 segment);
void* MemCopy(void* dest, void* src, s32 size);
void func_800694A0(GlobalContext* globalCtx, s16 drawId);
void Audio_PlaySoundAtPosition(GlobalContext* globalCtx, Vec3f* pos2, s32 radius, u16 sfxId);
u16 ElfMessage_GetSariaText(GlobalContext* globalCtx);
u16 ElfMessage_GetCUpText(GlobalContext* globalCtx);
u16 Text_GetFaceReaction(GlobalContext* globalCtx, u32 reactionSet);
void func_8006C438(GlobalContext* globalCtx, s16 arg1);
s32 func_8006C4A4(GlobalContext*, s32);
void func_8006EE48(s32);
f32 func_8006F93C(u16, u16, u16);
f32 func_8006F9BC(u16, u16, u16, u16, u16);
f32 func_800746DC();
void func_800773A8(GlobalContext* globalCtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 func_800775CC();
void func_800775D8();
s32 func_800775E4();
void func_800775F0(u16);
void Lib_MemSet(u8* dest, size_t size, u8 val);
f32 Math_Coss(s16 angle);
f32 Math_Sins(s16 angle);
s32 Math_ApproxUpdateScaledS(s16* fp, s16 target, s16 step);
s32 Math_ApproxS(s16* fp, s16 target, s16 step);
s32 Math_ApproxF(f32* fp, f32 target, f32 step);
s32 func_80077AF8(s16* fp, s16 target, s16 step);
s32 func_80077B58(s16* fp, s16 target, s16 step);
s32 func_80077C6C(f32* fp, f32 target, f32 incrStep, f32 decrStep);
s16 Math_Rand_S16Offset(s16 base, s16 range);
void Math_Vec3f_Copy(Vec3f* dest, Vec3f* src);
void Math_Vec3s_ToVec3f(Vec3f* dest, Vec3s* src);
void Math_Vec3f_Sum(Vec3f* a, Vec3f* b, Vec3f* dest);
void Math_Vec3f_Diff(Vec3f* a, Vec3f* b, Vec3f* dest);
void Math_Vec3s_DiffToVec3f(Vec3f* dest, Vec3s* a, Vec3s* b);
void Math_Vec3f_Scale(Vec3f* vec, f32 scaleF);
f32 Math_Vec3f_DistXYZ(Vec3f* a, Vec3f* b);
f32 Math_Vec3f_DistXYZAndStoreDiff(Vec3f* a, Vec3f* b, Vec3f* dest);
f32 Math_Vec3f_DistXZ(Vec3f* a, Vec3f* b);
s16 Math_Vec3f_Yaw(Vec3f* a, Vec3f* b);
s16 Math_Vec3f_Pitch(Vec3f* a, Vec3f* b);
void Actor_ProcessInitChain(Actor* actor, InitChainEntry* initChain);
f32 Math_SmoothScaleMaxMinF(f32* pValue, f32 target, f32 scale, f32 maxStep, f32 minStep);
void Math_SmoothScaleMaxF(f32* pValue, f32 target, f32 scale, f32 maxStep);
void Math_SmoothDownscaleMaxF(f32* pValue, f32 scale, f32 maxStep);
s16 Math_SmoothScaleMaxMinS(s16* pValue, s16 target, s16 invScale, s16 maxStep, s16 minStep);
void Math_SmoothScaleMaxS(s16* pValue, s16 target, s16 invScale, s16 maxStep);
void Color_RGBA8_Copy(Color_RGBA8* dst, Color_RGBA8* src);
void func_80078884(u16 sfxId);
void func_800788CC(u16 sfxId);
void func_80078914(Vec3f* arg0, u16 sfxId);
void Health_InitData(GlobalContext* globalCtx);
void Health_UpdateData(GlobalContext* globalCtx);
void Interface_DrawHealth(GlobalContext* globalCtx);
void Health_HandleCriticalAlarm(GlobalContext* globalCtx);
void Lights_InitPositionalLight(LightInfoPositional* info, s16 posX, s16 posY, s16 posZ, u8 red, u8 green, u8 blue,
                                s16 radius, u32 type);
void Lights_InitType0PositionalLight(LightInfoPositional* info, s16 posX, s16 posY, s16 posZ, u8 red, u8 green, u8 blue,
                                     s16 radius);
void Lights_InitType2PositionalLight(LightInfoPositional* info, s16 posX, s16 posY, s16 posZ, u8 red, u8 green, u8 blue,
                                     s16 radius);
void Lights_SetPositionalLightColorAndRadius(LightInfoPositional* info, u8 red, u8 green, u8 blue, s16 radius);
void Lights_InitDirectional(LightInfoDirectional* info, s8 dirX, s8 dirY, s8 dirZ, u8 red, u8 green, u8 blue);
void Lights_MapperInit(LightMapper* mapper, u8 red, u8 green, u8 blue);
z_Light* Lights_FindFreeSlot();
void Lights_Free(z_Light* light);
void func_8007A614(GlobalContext* globalCtx, LightingContext* lightCtx);
void func_8007A698(LightingContext* lightCtx, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5);
void Lights_SetAmbientColor(LightingContext* lightCtx, u8 red, u8 green, u8 blue);
LightMapper* Lights_CreateMapper(LightingContext* lightCtx, GraphicsContext* gfxCtx);
void Lights_ClearHead(GlobalContext* globalCtx, LightingContext* lightCtx);
void Lights_RemoveAll(GlobalContext* globalCtx, LightingContext* lightCtx);
z_Light* Lights_Insert(GlobalContext* globalCtx, LightingContext* lightCtx, LightInfo* info);
void Lights_Remove(GlobalContext* globalCtx, LightingContext* lightCtx, z_Light* light);
LightMapper* func_8007A960(GraphicsContext* gfxCtx, u8 red, u8 green, u8 blue);
void ZeldaArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* ZeldaArena_Malloc(u32 size);
void* ZeldaArena_MallocDebug(u32 size, const char* file, s32 line);
void* ZeldaArena_MallocR(u32 size);
void* ZeldaArena_MallocRDebug(u32 size, const char* file, s32 line);
void* ZeldaArena_Realloc(void* ptr, u32 newSize);
void* ZeldaArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void ZeldaArena_Free(void* ptr);
void ZeldaArena_FreeDebug(void* ptr, const char* file, s32 line);
void* ZeldaArena_Calloc(u32 num, u32 size);
void ZeldaArena_Display();
void ZeldaArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void ZeldaArena_Check();
void ZeldaArena_Init(void* start, u32 size);
void ZeldaArena_Cleanup();
u8 ZeldaArena_IsInitalized();
void MapMark_Init(GlobalContext* globalCtx);
void MapMark_ClearPointers(GlobalContext* globalCtx);
void MapMark_DrawConditionally(GlobalContext* globalCtx);
void PreNmiBuff_Init(PreNmiBuff* this);
void PreNmiBuff_SetReset(PreNmiBuff* this);
u32 PreNmiBuff_IsResetting(PreNmiBuff* this);
void MsgEvent_SendNullTask();
f32 func_8007BF90(Vec3f*, Vec3f*);
s16 func_800800F8(GlobalContext* globalCtx, u32 arg1, u32 arg2, Actor* actor, u32 arg4);
void func_80080788(s32, s32);
void func_80080F68(GlobalContext* globalCtx);
void Interface_DrawMinimap(GlobalContext* globalCtx);
void func_8008226C(GlobalContext* globalCtx);
void Interface_ChangeAlpha(u16 alphaType);
void Interface_SetSceneRestrictions(GlobalContext* globalCtx);
void Inventory_SwapAgeEquipment(void);
void Interface_InitHorsebackArchery(GlobalContext* globalCtx);
void func_800849EC(GlobalContext* globalCtx);
void Interface_LoadItemIcon1(GlobalContext* globalCtx, u16 button);
void Interface_LoadItemIcon2(GlobalContext* globalCtx, u16 button);
void func_80084BF4(GlobalContext* globalCtx, u16 flag);
u8 Item_Give(GlobalContext* globalCtx, u8 item);
u8 Item_CheckObtainability(u8 item);
void Inventory_DeleteItem(u16 item, u16 invSlot);
s32 Inventory_ReplaceItem(GlobalContext* globalCtx, u16 oldItem, u16 newItem);
s32 Inventory_HasEmptyBottle(void);
s32 Inventory_HasSpecificBottle(u8 bottleItem);
void Inventory_UpdateBottleItem(GlobalContext* globalCtx, u8 item, u8 cButton);
s32 Inventory_ConsumeFairy(GlobalContext* globalCtx);
void Interface_SetDoAction(GlobalContext* globalCtx, u16 action);
void Interface_SetNaviCall(GlobalContext* globalCtx, u16 naviCallState);
void Interface_LoadActionLabelB(GlobalContext* globalCtx, u16 action);
s32 Health_ChangeBy(GlobalContext* globalCtx, s16 healthChange);
void Rupees_ChangeBy(s16 rupeeChange);
void Inventory_ChangeAmmo(s16 item, s16 ammoChange);
void func_80087680(GlobalContext* globalCtx);
void func_800876C8(GlobalContext* globalCtx);
s32 func_80087708(GlobalContext* globalCtx, s16 arg1, s16 arg2);
void func_80088B34(s16 arg0);
void Interface_Draw(GlobalContext* globalCtx);
void Interface_Update(GlobalContext* globalCtx);
Path* Path_GetByIndex(GlobalContext* globalCtx, s16 index, s16 max);
f32 Path_OrientAndGetDistSq(Actor* actor, Path* path, s16 waypoint, s16* yaw);
void Path_CopyLastPoint(Path* path, Vec3f* dest);
s32 func_8008E8DC(GlobalContext*, Player*);
s32 func_8008E988(GlobalContext*);
s32 func_8008E9C4(Player* player);
s32 func_8008E9D0(Player* player);
void func_8008ECAC(GlobalContext*, Player* player);
void func_8008EDF0(Player*);
s32 func_8008EF44(GlobalContext*, s32);
u8 func_8008F080(GlobalContext*);
void func_8008F08C(GlobalContext*);
s32 func_8008F098(GlobalContext*);
s32 func_8008F0AC(GlobalContext*);
s32 func_8008F0D8(Player* player, s32);
s32 func_8008F104(Player* player);
s32 func_8008F128(Player* player);
s32 func_8008F158(s32);
void func_8008F180(Player* player);
s32 func_8008F1A0(Player* player);
s32 func_8008F224(Player* player, s32);
void func_8008F250(Player* player);
s32 func_8008F270(Player* player, s32);
s32 func_8008F29C(Player* player);
s32 func_8008F2F8(GlobalContext*);
u8 func_80090480(GlobalContext* globalCtx, Collider* collider, void* a2, Vec3f* a3, Vec3f* a4);
void PreNMI_Init(PreNMIContext* prenmiCtx);
Vec3f* Quake_AddVec(Vec3f* dst, Vec3f* arg1, struct_80045714* arg2);
void Quake_UpdateShakeInfo(QuakeRequest* req, ShakeInfo* shake, f32 y, f32 x);
s16 Quake_Callback1(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback2(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback3(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback4(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback5(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback6(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_GetFreeIndex();
QuakeRequest* Quake_AddImpl(Camera* cam, u32 callbackIdx);
void Quake_Remove(QuakeRequest* req);
QuakeRequest* Quake_GetRequest(s16 idx);
QuakeRequest* Quake_SetValue(s16 idx, s16 valueType, s16 value);
u32 Quake_SetSpeed(s16 idx, s16 value);
u32 Quake_SetCountdown(s16 idx, s16 value);
s16 Quake_GetCountdown(s16 idx);
u32 Quake_SetQuakeValues(s16 idx, s16 y, s16 x, s16 zoom, s16 rotZ);
u32 Quake_SetUnkValues(s16 idx, s16 arg1, SubQuakeRequest14 arg2);
void Quake_Init();
s16 Quake_Add(Camera* cam, u32 callbackIdx);
u32 Quake_RemoveFromIdx(s16 idx);
s16 Quake_Calc(Camera* camera, UnkQuakeCalcStruct* camData);
Gfx* Gfx_SetFog(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 n, s32 f);
Gfx* Gfx_SetFogWithSync(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 n, s32 f);
Gfx* Gfx_SetFog2(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 n, s32 f);
Gfx* Gfx_CallSetupDL(Gfx* gfx, u32 i);
Gfx* func_800937C0(Gfx* gfx);
Gfx* func_80093808(Gfx* gfx);
void func_800938B4(GraphicsContext* gfxCtx);
void func_8009398C(GraphicsContext* gfxCtx);
void func_80093AD0(GraphicsContext* gfxCtx);
void func_80093BA8(GraphicsContext* gfxCtx);
void func_80093C80(GlobalContext* globalCtx);
void func_80093D18(GraphicsContext* gfxCtx);
void func_80093D84(GraphicsContext* gfxCtx);
Gfx* func_80093F34(Gfx* gfx);
Gfx* func_80093F58(Gfx* gfx);
void func_80094044(GraphicsContext* gfxCtx);
void func_800940B0(GraphicsContext* gfxCtx);
void func_800942F0(GraphicsContext* gfxCtx);
void func_8009435C(GraphicsContext* gfxCtx);
Gfx* func_800944A0(Gfx* gfx);
void func_80094520(GraphicsContext* gfxCtx);
void func_8009457C(Gfx** gfxp);
void func_800945A0(GraphicsContext* gfxCtx);
void func_80094678(GraphicsContext* gfxCtx);
Gfx* func_800946E4(Gfx* gfx);
Gfx* func_800947AC(Gfx* gfx);
void func_80094A14(GraphicsContext* gfxCtx);
void func_80094C50(GraphicsContext* gfxCtx);
void Gfx_BranchTexScroll(Gfx** gfxp, u32 x, u32 y, s32 width, s32 height);
Gfx* func_80094E78(GraphicsContext* gfxCtx, u32 x, u32 y);
Gfx* Gfx_TexScroll(GraphicsContext* gfxCtx, u32 x, u32 y, s32 width, s32 height);
Gfx* Gfx_TwoTexScroll(GraphicsContext* gfxCtx, s32 tile1, u32 x1, u32 y1, s32 width1, s32 height1, s32 tile2, u32 x2,
                      u32 y2, s32 width2, s32 height2);
Gfx* Gfx_TwoTexScrollEnvColor(GraphicsContext* gfxCtx, s32 tile1, u32 x1, u32 y1, s32 width1, s32 height1, s32 tile2,
                              u32 x2, u32 y2, s32 width2, s32 height2, s32 r, s32 g, s32 b, s32 a);
void func_80095248(GraphicsContext* gfxCtx, u8 r, u8 g, u8 b);
void func_80095974(GraphicsContext* gfxCtx);
void func_80095AA0(GlobalContext* globalCtx, Room* room, s32 arg2, s32 arg3);
void func_80096FD4(GlobalContext* globalCtx, Room* room);
u32 func_80096FE8(GlobalContext* globalCtx, RoomContext* roomCtx);
s32 func_8009728C(GlobalContext* globalCtx, RoomContext* roomCtx, s32 roomNum);
s32 func_800973FC(GlobalContext* globalCtx, RoomContext* roomCtx);
void Room_Draw(GlobalContext* globalCtx, Room* room, u32 flags);
void func_80097534(GlobalContext* globalCtx, RoomContext* roomCtx);
void Sample_Calc(SampleContext* this);
void Sample_Draw(SampleContext* this);
void Sample_Update(SampleContext* this);
void Sample_Destroy(SampleContext* this);
void Sample_SetupView(SampleContext* this);
void Sample_LoadTitleStatic(SampleContext* this);
void Sample_Init(SampleContext* this);
void Inventory_ChangeEquipment(s16 equipment, u16 value);
u8 Inventory_DeleteEquipment(GlobalContext* globalCtx, s16 equipment);
void Inventory_ChangeUpgrade(s16 upgrade, s16 value);
void Object_InitBank(GlobalContext* globalCtx, ObjectContext* objectCtx);
void Object_UpdateBank(ObjectContext* objectCtx);
s32 Object_GetIndex(ObjectContext* objectCtx, s16 objectId);
s32 Object_IsLoaded(ObjectContext* objectCtx, s32 bankIndex);
void func_800981B8(ObjectContext* objectCtx);
s32 Scene_ExecuteCommands(GlobalContext* globalCtx, SceneCmd* sceneCmd);
void func_80098CBC(GlobalContext* globalCtx, u8* nbTransitionActors);
void func_800994A0(GlobalContext* globalCtx);
void Scene_Draw(GlobalContext* globalCtx);
void SkelAnime_LodDraw(GlobalContext* globalCtx, Skeleton* skeleton, Vec3s* actorDrawTable,
                       SkelAnime_LimbUpdateMatrix updateMtxFunc, SkelAnime_LimbAppendDlist appendDlistFunc,
                       Actor* actor, s32 dListIndex);
void SkelAnime_LodDrawSV(GlobalContext* globalCtx, Skeleton* skeleton, Vec3s* actorDrawTable, s32 dListCount,
                         SkelAnime_LimbUpdateMatrix updateMtxFunc, SkelAnime_LimbAppendDlist appendDlistFunc,
                         Actor* actor, s32 dListIndex);
void SkelAnime_Draw(GlobalContext* globalCtx, Skeleton* skeleton, Vec3s* actorDrawTable,
                    SkelAnime_LimbUpdateMatrix updateMtxFunc, SkelAnime_LimbAppendDlist appendDlistFunc, Actor* actor);
void SkelAnime_DrawSV(GlobalContext* globalCtx, Skeleton* skeleton, Vec3s* actorDrawTable, s32 dListCount,
                      SkelAnime_LimbUpdateMatrix updateMtxFunc, SkelAnime_LimbAppendDlist appendDlistFunc,
                      Actor* actor);
s16 SkelAnime_GetFrameCount(GenericAnimationHeader* animationSeg);
Gfx* SkelAnime_Draw2(GlobalContext* globalCtx, Skeleton* skeleton, Vec3s* actorDrawTable,
                     SkelAnime_LimbUpdateMatrix2 updateMtxFunc, SkelAnime_LimbAppendDlist2 appendDlistFunc,
                     Actor* actor, Gfx* gfx);
Gfx* SkelAnime_DrawSV2(GlobalContext* globalCtx, Skeleton* skeleton, Vec3s* actorDrawTable, s32 dListCount,
                       SkelAnime_LimbUpdateMatrix2 updateMtxFunc, SkelAnime_LimbAppendDlist2 appendDlistFunc,
                       Actor* actor, Gfx* gfx);
void SkelAnime_InterpolateVec3s(s32, Vec3s*, Vec3s*, Vec3s*, f32);
void SkelAnime_AnimationCtxReset(AnimationContext* animationCtx);
void func_800A32F4(GlobalContext* globalCtx);
void func_800A3310(GlobalContext* globalCtx);
void SkelAnime_LoadLinkAnimetion(GlobalContext* globalCtx, LinkAnimetionEntry* linkAnimetionSeg, s32 frame,
                                 s32 limbCount, void* ram);
void SkelAnime_LoadAnimationType1(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src);
void SkelAnime_LoadAnimationType2(GlobalContext* globalCtx, s32 limbCount, Vec3s* arg2, Vec3s* arg3, f32 arg4);
void SkelAnime_LoadAnimationType3(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src, u8* index);
void SkelAnime_LoadAnimationType4(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src, u8* index);
void SkelAnime_LoadAnimationType5(GlobalContext* globalCtx, Actor* actor, SkelAnime* skelAnime, f32 arg3);
void func_800A390C(GlobalContext* globalCtx, AnimationContext* animationCtx);
void SkelAnime_InitLinkAnimetion(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg,
                                 LinkAnimetionEntry* linkAnimetionEntrySeg, s32 flags, Vec3s* actorDrawTbl, Vec3s* arg6,
                                 s32 limbBufCount);
void func_800A3B8C(SkelAnime* skelAnime);
s32 func_800A3BC0(GlobalContext* globalCtx, SkelAnime* skelAnime);
void func_800A3C9C(GlobalContext* globalCtx, SkelAnime* skelAnime);
void SkelAnime_SetTransition(GlobalContext* globalCtx, SkelAnime* skelAnime, f32 transitionRate);
void SkelAnime_ChangeLinkAnim(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimetionEntry* linkAnimetionEntrySeg,
                              f32 playbackSpeed, f32 frame, f32 frameCount, u8 arg6, f32 transitionRate);
void SkelAnime_ChangeLinkAnimDefaultStop(GlobalContext* globalCtx, SkelAnime* skelAnime,
                                         LinkAnimetionEntry* linkAnimetionEntrySeg);
void SkelAnime_ChangeLinkAnimPlaybackStop(GlobalContext* globalCtx, SkelAnime* skelAnime,
                                          LinkAnimetionEntry* linkAnimetionEntrySeg, f32 playbackSpeed);
void SkelAnime_ChangeLinkAnimDefaultRepeat(GlobalContext* globalCtx, SkelAnime* skelAnime,
                                           LinkAnimetionEntry* linkAnimetionEntrySeg);
void SkelAnime_ChangeLinkAnimPlaybackRepeat(GlobalContext* globalCtx, SkelAnime* skelAnime,
                                            LinkAnimetionEntry* linkAnimetionEntrySeg, f32 playbackSpeed);
void func_800A41FC(GlobalContext* globalCtx, SkelAnime* skelAnime);
void func_800A425C(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimetionEntry* linkAnimetionEntrySeg,
                   f32 frame);
void func_800A42A0(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimetionEntry* linkAnimetionEntrySeg,
                   f32 frame);
void func_800A42E4(GlobalContext* globalCtx, SkelAnime* skelAnime, f32 frame);
void func_800A431C(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimetionEntry* linkAnimetionEntrySeg,
                   f32 transitionFrame, LinkAnimetionEntry* linkAnimetionEntrySeg2, f32 frame, f32 transitionRate,
                   Vec3s* actorDrawTable);
void func_800A43B8(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimetionEntry* linkAnimetionEntrySeg,
                   f32 transitionFrame, LinkAnimetionEntry* linkAnimetionEntrySeg2, f32 frame, f32 transitionRate,
                   Vec3s* arg7);
s32 func_800A4530(SkelAnime* skelAnime, f32 arg1);
void SkelAnime_Init(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg,
                    AnimationHeader* animationseg, Vec3s* actorDrawTable, Vec3s* arg5, s32 limbCount);
void SkelAnime_InitSV(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg,
                      AnimationHeader* animationseg, Vec3s* actorDrawTable, Vec3s* arg5, s32 limbCount);
void SkelAnime_InitSkin(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg,
                        AnimationHeader* animationseg);
s32 SkelAnime_FrameUpdateMatrix(SkelAnime* skelAnime);
void SkelAnime_ChangeAnimImpl(SkelAnime* skelAnime, AnimationHeader* animationseg, f32 playbackSpeed, f32 frame,
                              f32 frameCount, u8 unk1, f32 transitionRate, s8 unk2);
void SkelAnime_ChangeAnim(SkelAnime* skelAnime, AnimationHeader* animationseg, f32 playbackSpeed, f32 unk0,
                          f32 frameCount, u8 unk1, f32 transitionRate);
void SkelAnime_ChangeAnimDefaultStop(SkelAnime* skelAnime, AnimationHeader* animationseg);
void SkelAnime_ChangeAnimTransitionStop(SkelAnime* skelAnime, AnimationHeader* animationseg, f32 transitionRate);
void SkelAnime_ChangeAnimPlaybackStop(SkelAnime* skelAnime, AnimationHeader* animationseg, f32 playbackSpeed);
void SkelAnime_ChangeAnimDefaultRepeat(SkelAnime* skelAnime, AnimationHeader* animationseg);
void SkelAnime_ChangeAnimTransitionRepeat(SkelAnime* skelAnime, AnimationHeader* animationseg, f32 transitionRate);
void SkelAnime_ChangeAnimPlaybackRepeat(SkelAnime* skelAnime, AnimationHeader* animationseg, f32 playbackSpeed);
void SkelAnime_AnimReverse(SkelAnime* skelAnime);
void func_800A5428(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, u8* index);
void func_800A54FC(SkelAnime* skelAnime, Vec3f* pos, s16 angle);
s32 func_800A56C8(SkelAnime* skelAnime, f32 arg1);
void SkelAnime_Free(SkelAnime* skelAnime, GlobalContext* globalCtx);
void func_800A76A4(MtxF* dest, f32 x, f32 y, f32 z);
void func_800A7A24(MtxF* dest, f32 x, f32 y, f32 z);
void func_800A9D40(u32 addr, u8 handleType, u8 handleDomain, u8 handleLatency, u8 handlePageSize, u8 handleRelDuration,
                   u8 handlePulse, u32 handleSpeed);
void func_800A9E14(void* dramAddr, size_t size, s32 arg2);
void Sram_ReadWrite(s32 arg0, void* dramAddr, size_t size, s32 arg3);
void func_800A9F30(s32, s32);
void func_800A9F6C(f32, u8, u8, u8);
void func_800AA000(f32, u8, u8, u8);
void func_800AA0B4();
u32 func_800AA148();
void func_800AA15C();
void func_800AA16C();
void func_800AA178(u32);
void func_800AA190(UnkViewStruct* arg0, Viewport* viewport);
View* func_800AA1F8(GraphicsContext* gfxCtx);
void func_800AA250(View* view);
void func_800AA278(View*, GraphicsContext*);
void func_800AA358(View* view, Vec3f* vec1, Vec3f* vec2, Vec3f* vec3);
void func_800AA3F0(View* view, Vec3f* vec1, Vec3f* vec2, Vec3f* vec3);
void func_800AA43C(View* view, f32 arg1);
void func_800AA454(View* view, f32* arg1);
void func_800AA460(View* view, f32 fieldOfView, f32 fogDistance, f32 zDepth);
void func_800AA48C(View* view, f32* fieldOfView, f32* fogDistance, f32* zDepth);
void func_800AA4A8(View* view, f32 fieldOfView, f32 fogDistance, f32 zDepth);
void func_800AA4E0(View* view, f32* fieldOfView, f32* fogDistance, f32* zDepth);
void func_800AA4FC(View* view, Viewport* viewport);
void func_800AA52C(View* view, Viewport* viewport);
void func_800AA550(View* view);
void func_800AA76C(View* view, f32 arg1, f32 arg2, f32 arg3);
void func_800AA78C(View* view, f32 arg1, f32 arg2, f32 arg3);
void func_800AA7AC(View* view, f32 arg1);
void func_800AA7B8(View* view);
void func_800AA814(View* view);
void func_800AA840(View* view, Vec3f vec1, Vec3f vec2, f32 arg3);
s32 func_800AA890(View* view, Mtx* mtx);
void func_800AAA50(View* view, s32 arg1);
s32 func_800AAA9C(View* view);
s32 func_800AB0A8(View* view);
s32 func_800AB2C4(View* view);
s32 func_800AB560(View* view);
s32 func_800AB944(View* view);
s32 func_800ABE74(f32 eyeX, f32 eyeY, f32 eyeZ);
void PlayerCall_InitFuncPtrs();
void KaleidoManager_LoadOvl(KaleidoManagerOvl* ovl);
void KaleidoManager_ClearOvl(KaleidoManagerOvl* ovl);
void KaleidoManager_Init(GlobalContext* globalCtx);
void KaleidoManager_Destroy();
void* KaleidoManager_GetRamAddr(void* vram);
void KaleidoScopeCall_LoadPlayer();
void KaleidoScopeCall_Init(GlobalContext* globalCtx);
void KaleidoScopeCall_Destroy(GlobalContext* globalCtx);
void KaleidoScopeCall_Update(GlobalContext* globalCtx);
void KaleidoScopeCall_Draw(GlobalContext* globalCtx);
s32 func_800BC56C(GlobalContext*, s16);
void func_800BC88C(GlobalContext*);
Gfx* func_800BC8A0(GlobalContext* globalCtx, Gfx* a1);
void func_800BC8EC(GlobalContext*);
s32 func_800BCA64(void);
s32 func_800BFC84(GlobalContext* globalCtx);
f32 func_800BFCB8(GlobalContext* globalCtx, MtxF* a1, Vec3f* a2);
void* func_800BFE5C(GlobalContext* globalCtx, RomFile* file);
s16 func_800C030C(GlobalContext* globalCtx);
Camera* func_800C04A4(GlobalContext*, s16);
void func_800C0704(GlobalContext*, s16, f32);
void func_800C0C88(GlobalContext* globalCtx);
void func_800C0AF4(GlobalContext*, s8, s16);
void func_800C0B60(GlobalContext* globalCtx);
void func_800C0BB4(GlobalContext* globalCtx);
s32 func_800C0D28(GlobalContext* globalCtx);
void THGA_Ct(TwoHeadGfxArena* thga, Gfx* start, u32 size);
void THGA_Dt(TwoHeadGfxArena* thga);
u32 THGA_IsCrash(TwoHeadGfxArena* thga);
void THGA_Init(TwoHeadGfxArena* thga);
s32 THGA_GetSize(TwoHeadGfxArena* thga);
Gfx* THGA_GetHead(TwoHeadGfxArena* thga);
void THGA_SetHead(TwoHeadGfxArena* thga, Gfx* start);
Gfx* THGA_GetTail(TwoHeadGfxArena* thga);
Gfx* THGA_AllocStartArray8(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocStart8(TwoHeadGfxArena* thga);
Gfx* THGA_AllocStart8Wrapper(TwoHeadGfxArena* thga);
Gfx* THGA_AllocEnd(TwoHeadGfxArena* thga, u32 size);
Gfx* THGA_AllocEndArray64(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocEnd64(TwoHeadGfxArena* thga);
Gfx* THGA_AllocEndArray16(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocEnd16(TwoHeadGfxArena* thga);
void* THA_GetHead(TwoHeadArena* tha);
void THA_SetHead(TwoHeadArena* tha, void* start);
void* THA_GetTail(TwoHeadArena* tha);
void* THA_AllocStart(TwoHeadArena* tha, u32 size);
void* THA_AllocStart1(TwoHeadArena* tha);
void* THA_AllocEnd(TwoHeadArena* tha, u32 size);
void* THA_AllocEndAlign16(TwoHeadArena* tha, u32 size);
void* THA_AllocEndAlign(TwoHeadArena* tha, u32 size, u32 mask);
s32 THA_GetSize(TwoHeadArena* tha);
u32 THA_IsCrash(TwoHeadArena* tha);
void THA_Init(TwoHeadArena* tha);
void THA_Ct(TwoHeadArena* tha, void* ptr, u32 size);
void THA_Dt(TwoHeadArena* tha);
void TitleSetup_InitImpl(GameState* gameState);
void TitleSetup_Destroy(GameState* gameState);
void TitleSetup_Init(GameState* gameState);
void* Game_Alloc(GameState* gameState, size_t size, char* file, s32 line);
void func_800C55D0(GameAlloc* this);
void* GameAlloc_MallocDebug(GameAlloc* this, u32 size, const char* file, s32 line);
void* GameAlloc_Malloc(GameAlloc* this, u32 size);
void GameAlloc_Free(GameAlloc* this, void* data);
void GameAlloc_Cleanup(GameAlloc* this);
void GameAlloc_Init(GameAlloc* this);
void Graph_FaultClient();
void Graph_DisassembleUCode(void* arg0);
void Graph_UCodeFaultClient(void* arg0);
void* Graph_InitTHGA(GraphicsContext* gfxCtx);
GameStateOverlay* Graph_GetNextGameState();
void Graph_Init(GraphicsContext* gfxCtx);
void Graph_Destroy(GraphicsContext* gfxCtx);
void Graph_TaskSet00(GraphicsContext* gfxCtx);
void Graph_Update(GraphicsContext* gfxCtx, GameState* gameState);
void Graph_ThreadEntry(void*);
void* Graph_Alloc(GraphicsContext* gfxCtx, size_t size);
void* Graph_Alloc2(GraphicsContext* gfxCtx, size_t size);
void Graph_OpenDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_CloseDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line);
Gfx* Graph_GfxPlusOne(Gfx* gfx);
Gfx* Graph_BranchDlist(Gfx* gfx, Gfx* dst);
void* Graph_DlistAlloc(Gfx** gfx, u32 size);
ListAlloc* ListAlloc_Init(ListAlloc* this);
void* ListAlloc_Alloc(ListAlloc* this, u32 size);
void ListAlloc_Free(ListAlloc* this, void* data);
void ListAlloc_FreeAll(ListAlloc* this);
void Main_LogSystemHeap();
void Main(void*);
void func_800C7E08(Input*, u32);
void func_800C9644(u32 a0);
void SysCfb_Init(s32 n64dd);
u32 SysCfb_GetFbPtr(s32 idx);
u32 SysCfb_GetFbEnd();
f32 func_800CA720(f32);
f32 func_800CA774(f32);
s16 atan2s(f32 x, f32 y);
f32 atan2f(f32 x, f32 y);
void Matrix_Init(GameState* gameState);
void Matrix_Push(void);
void Matrix_Pull(void);
void Matrix_Get(MtxF* dest);
void Matrix_Put(MtxF* src);
void Matrix_Mult(MtxF* mf, u8 mode);
void Matrix_Translate(f32 x, f32 y, f32 z, u8 mode);
void Matrix_Scale(f32 x, f32 y, f32 z, u8 mode);
void Matrix_RotateX(f32 x, u8 mode);
void Matrix_RotateY(f32 y, u8 mode);
void Matrix_RotateZ(f32 z, u8 mode);
void Matrix_RotateZYX(s16 x, s16 y, s16 z, u8 mode);
void Matrix_TranslateThenRotateZYX(Vec3f* arg0, Vec3s* arg1);
void func_800D1694(f32 x, f32 y, f32 z, Vec3s* vec);
Mtx* Matrix_MtxFToMtx(MtxF* src, Mtx* dest);
Mtx* Matrix_ToMtx(Mtx* dest, char* file, s32 line);
Mtx* Matrix_NewMtx(GraphicsContext* gfxCtx, char* file, s32 line);
Mtx* Matrix_MtxFToNewMtx(MtxF* src, GraphicsContext* gfxCtx);
void Matrix_MultVec3f(Vec3f* src, Vec3f* dest);
void Matrix_MtxFCopy(MtxF* dest, MtxF* src);
void Matrix_MtxToMtxF(Mtx* src, MtxF* dest);
void Matrix_MultVec3fExt(Vec3f* src, Vec3f* dest, MtxF* mf);
void Matrix_Reverse(MtxF* mf);
void func_800D1FD4(MtxF* mf);
void func_800D20CC(MtxF* mf, Vec3s* vec, s32 flag);
void func_800D2264(MtxF* mf, Vec3s* vec, s32 flag);
void func_800D23FC(f32 f, Vec3f* vec, u8 mode);
MtxF* Matrix_CheckFloats(MtxF* mf, char* file, s32 line);
void func_800D2CEC(Mtx* mtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void IrqMgr_AddClient(IrqMgr* this, IrqMgrClient* c, OSMesgQueue* msgQ);
void IrqMgr_RemoveClient(IrqMgr* this, IrqMgrClient* c);
void IrqMgr_SendMesgForClient(IrqMgr* this, OSMesg msg);
void IrqMgr_JamMesgForClient(IrqMgr* this, OSMesg msg);
void IrqMgr_HandlePreNMI(IrqMgr* this);
void IrqMgr_CheckStack();
void IrqMgr_HandlePRENMI450(IrqMgr* this);
void IrqMgr_HandlePRENMI480(IrqMgr* this);
void IrqMgr_HandlePRENMI500(IrqMgr* this);
void IrqMgr_HandleRetrace(IrqMgr* this);
void IrqMgr_ThreadEntry(void* arg0);
void IrqMgr_Create(IrqMgr* this, void* stack, OSPri pri, u8 retraceCount);
void DebugArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* DebugArena_Malloc(u32 size);
void* DebugArena_MallocDebug(u32 size, const char* file, s32 line);
void* DebugArena_MallocR(u32 size);
void* DebugArena_MallocRDebug(u32 size, const char* file, s32 line);
void* DebugArena_Realloc(void* ptr, u32 newSize);
void* DebugArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void DebugArena_Free(void* ptr);
void DebugArena_FreeDebug(void* ptr, const char* file, s32 line);
void* DebugArena_Calloc(u32 num, u32 size);
void DebugArena_Display();
void DebugArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void DebugArena_Check();
void DebugArena_Init(void* start, u32 size);
void DebugArena_Cleanup();
u8 DebugArena_IsInitalized();
void Fault_SleepImpl(u32);
void Fault_ClientProcessThread(FaultClientContext*);
void Fault_ProcessClientContext(FaultClientContext*);
u32 Fault_ProcessClient(u32, u32, u32);
void Fault_AddClient(FaultClient*, void*, void*, void*);
void Fault_RemoveClient(FaultClient*);
void Fault_AddAddrConvClient(FaultAddrConvClient*, void*, void*);
void Fault_RemoveAddrConvClient(FaultAddrConvClient*);
u32 Fault_ConvertAddress(FaultAddrConvClient*);
void Fault_Sleep(u32);
void Fault_PadCallback(Input*);
void Fault_UpdatePadImpl();
u32 Fault_WaitForInputImpl();
void Fault_WaitForInput();
void Fault_DrawRec(s32, s32, s32, s32, u16);
void Fault_FillScreenBlack();
void Fault_FillScreenRed();
void Fault_DrawCornerRec(u16);
void Fault_PrintFReg(s32, f32*);
void Fault_LogFReg(s32, f32*);
void Fault_PrintFPCR(u32);
void Fault_LogFPCR(u32);
void Fault_PrintThreadContext(OSThread*);
void Fault_LogThreadContext(OSThread*);
OSThread* Fault_FindFaultedThread();
void Fault_Wait5Seconds();
void Fault_WaitForButtonCombo();
void Fault_DrawMemDumpPage(const char*, u32*, u32);
void Fault_DrawMemDump(u32, u32, u32, u32);
void Fault_DrawStackTrace(OSThread*, s32, s32, u32);
void Fault_LogStackTrace(OSThread*, u32);
void Fault_ResumeThread(OSThread*);
void Fault_CommitFB();
void Fault_ProcessClients();
void Fault_UpdatePad();
void Fault_ThreadEntry(void*);
void Fault_SetFB(void*, u16, u16);
void Fault_Start(void);
void Fault_HangupFaultClient(const char*, const char*);
void Fault_AddHungupAndCrashImpl(const char*, const char*);
void Fault_AddHungupAndCrash(const char*, u32);
void FaultDrawer_SetOsSyncPrintfEnabled(u32);
void FaultDrawer_DrawRecImpl(s32, s32, s32, s32, u16);
void FaultDrawer_DrawChar(char);
s32 FaultDrawer_ColorToPrintColor(u16);
void FaultDrawer_UpdatePrintColor();
void FaultDrawer_SetForeColor(u16);
void FaultDrawer_SetBackColor(u16);
void FaultDrawer_SetFontColor(u16);
void FaultDrawer_SetCharPad(s8, s8);
void FaultDrawer_SetCursor(s32, s32);
void FaultDrawer_FillScreen();
u32 FaultDrawer_FormatStringFunc(u32, const char*, s32);
void FaultDrawer_VPrintf(const char*, char*);
void FaultDrawer_Printf(const char*, ...);
void FaultDrawer_DrawText(s32, s32, const char*, ...);
void FaultDrawer_SetDrawerFB(void*, u16, u16);
void FaultDrawer_SetInputCallback(void (*)());
void FaultDrawer_SetDefault();
void func_800F436C(s32 arg0, s16 arg1, f32 arg2);
void func_800F4C58(Vec3f*, u16, u8);
void func_800F595C(u16);
void func_800F59E8(u16);
void func_800F68BC(s8);
void func_800F6964(u16);
void func_800F7260(u16);
void Audio_PlaySoundGeneral(u16 sfxId, Vec3f* a1, u32 a2, u32* a3, u32* a4, u32* a5);
void func_800F8D04(u32 a0);
void Audio_SetBGM(u32 bgmID);
u16 func_800FA0B4(s32 a0);
void GfxPrint_InitDlist(GfxPrint*);
void GfxPrint_SetColor(GfxPrint*, u32, u32, u32, u32);
void GfxPrint_SetPosPx(GfxPrint*, s32, s32);
void GfxPrint_SetPos(GfxPrint*, s32, s32);
void GfxPrint_SetBasePosPx(GfxPrint*, s32, s32);
void GfxPrint_PrintCharImpl(GfxPrint*, u8);
void GfxPrint_PrintChar(GfxPrint*, u8);
void GfxPrint_PrintStringWithSize(GfxPrint*, const void*, size_t, size_t);
GfxPrint* GfxPrint_Callback(GfxPrint*, const char*, size_t);
void GfxPrint_Ctor(GfxPrint*);
void GfxPrint_Dtor(GfxPrint*);
void GfxPrint_Open(GfxPrint*, Gfx*);
Gfx* GfxPrint_Close(GfxPrint*);
void GfxPrint_VPrintf(GfxPrint*, const char*, va_list);
void GfxPrint_Printf(GfxPrint*, const char*, ...);
void func_800FBCE0();
void func_800FBFD8();
void* Overlay_AllocateAndLoad(u32 vRomStart, u32 vRomEnd, void* vRamStart, void* vRamEnd);
void Overlay_DoRelocation(void* allocatedVRamAddress, OverlayRelocationSection* overlayInfo, void* vRamAddress);
s32 Overlay_Load(u32 vRomStart, u32 vRomEnd, void* vRamStart, void* vRamEnd, void* allocatedVRamAddress);
void SystemHeap_Init(void* start, u32 size);
f32 Math_tanf(f32 x);
f32 Math_nearbyintf(f32 x);
f32 Math_atanf_taylor_q(f32 x);
f32 Math_atanf_taylor(f32 x);
f32 Math_atanf_cfrac(f32 x);
f32 Math_atanf(f32 x);
f32 Math_atan2f(f32 y, f32 x);
f32 Math_asinf(f32 x);
f32 Math_acosf(f32 x);
f32 ceilf(f32 x);
f32 truncf(f32 x);
f32 roundf(f32 x);
f32 nearbyintf(f32 x);
void SystemArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* SystemArena_Malloc(u32 size);
void* SystemArena_MallocDebug(u32 size, const char* file, s32 line);
void* SystemArena_MallocR(u32 size);
void* SystemArena_MallocRDebug(u32 size, const char* file, s32 line);
void* SystemArena_Realloc(void* ptr, u32 newSize);
void* SystemArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void SystemArena_Free(void* ptr);
void SystemArena_FreeDebug(void* ptr, const char* file, s32 line);
void* SystemArena_Calloc(u32 num, u32 size);
void SystemArena_Display();
void SystemArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void SystemArena_Check();
void SystemArena_Init(void* start, u32 size);
void SystemArena_Cleanup();
u8 SystemArena_IsInitalized();
f32 Math_Rand_ZeroOne();
u32 ArenaImpl_GetFillAllocBlock(Arena* arena);
u32 ArenaImpl_GetFillFreeBlock(Arena* arena);
u32 ArenaImpl_GetCheckFreeBlock(Arena* arena);
void ArenaImpl_SetFillAllocBlock(Arena* arena);
void ArenaImpl_SetFillFreeBlock(Arena* arena);
void ArenaImpl_SetCheckFreeBlock(Arena* arena);
void ArenaImpl_UnsetFillAllocBlock(Arena* arena);
void ArenaImpl_UnsetFillFreeBlock(Arena* arena);
void ArenaImpl_UnsetCheckFreeBlock(Arena* arena);
void ArenaImpl_SetDebugInfo(ArenaNode* node, const char* file, s32 line, Arena* arena);
void ArenaImpl_LockInit(Arena* arena);
void ArenaImpl_Lock(Arena* arena);
void ArenaImpl_Unlock(Arena* arena);
ArenaNode* ArenaImpl_GetNextBlock(ArenaNode* node);
ArenaNode* ArenaImpl_GetPrevBlock(ArenaNode* node);
ArenaNode* ArenaImpl_GetLastBlock(Arena* arena);
void __osMallocInit(Arena* arena, void* start, u32 size);
void __osMallocAddBlock(Arena* arena, void* start, s32 size);
void ArenaImpl_RemoveAllBlocks(Arena* arena);
void __osMallocCleanup(Arena* arena);
u8 __osMallocIsInitalized(Arena* arena);
void __osMalloc_FreeBlockTest(Arena* arena, ArenaNode* node);
void* __osMalloc_NoLockDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMallocDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMallocRDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMalloc_NoLock(Arena* arena, u32 size);
void* __osMalloc(Arena* arena, u32 size);
void* __osMallocR(Arena* arena, u32 size);
void __osFree_NoLock(Arena* arena, void* ptr);
void __osFree(Arena* arena, void* ptr);
void __osFree_NoLockDebug(Arena* arena, void* ptr, const char* file, s32 line);
void __osFreeDebug(Arena* arena, void* ptr, const char* file, s32 line);
void* __osRealloc(Arena* arena, void* ptr, u32 newSize);
void* __osReallocDebug(Arena* arena, void* ptr, u32 newSize, const char* file, s32 line);
void ArenaImpl_GetSizes(Arena* arena, u32* outMaxFree, u32* outFree, u32* outAlloc);
void __osDisplayArena(Arena* arena);
void ArenaImpl_FaultClient(Arena* arena);
u32 __osCheckArena(Arena* arena);
u8 func_800FF334(Arena* arena);
f32 sinf(f32);
s16 sins(u16);
void func_80101E34(MtxF*, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_80103A70(void*, Gfx*, Hilite*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32,
                   s32, s32);
void func_80103D58(Mtx*, f32, f32, f32, f32, f32, f32, f32);
u32 osDpGetStatus(void);
void osDpSetStatus(u32 status);
void func_801045A4(Mtx*, f32, f32, f32, f32, f32, f32, f32);
f32 cosf(f32);
s16 coss(u16);
void osViSetEvent(OSMesgQueue* mq, OSMesg m, u32 retraceCount);
void func_80104D00(u8 a0);
u32 __osSpGetStatus();
void __osSpSetStatus(u32 status);
OSThread* __osGetCurrFaultedThread();
f32 absf(f32);
u8 func_80106BC8(GlobalContext* globalCtx);
void func_80106CCC(GlobalContext*);
void func_8010B680(GlobalContext*, u16, s32);
void func_8010B720(GlobalContext* globalCtx, u16 textId);
u8 func_8010BDBC(MessageContext* msgCtx);
void func_8011040C(void);
void func_80110990(GlobalContext* globalCtx);
void func_801109B0(GlobalContext* globalCtx);
void func_80110F68(GlobalContext* globalCtx);
void func_80112098(GlobalContext* globalCtx);
void Title_Init(TitleContext*);
void Title_Destroy(TitleContext* this);
void func_80801E44(GameState*);
void func_80801E0C(GameState*);
void Opening_Init(OpeningContext* this);
void Opening_Destroy(OpeningContext* this);
void func_80811A20(GameState*);
void func_80811A18(GameState*);
extern u8 _bootSegmentStart[]; extern u8 _bootSegmentEnd[];
extern u8 _bootSegmentRomStart[]; extern u8 _bootSegmentRomEnd[];
extern u8 _dmadataSegmentStart[]; extern u8 _dmadataSegmentEnd[];
extern u8 _dmadataSegmentRomStart[]; extern u8 _dmadataSegmentRomEnd[];
extern u8 _AudiobankSegmentRomStart[]; extern u8 _AudiobankSegmentRomEnd[];
extern u8 _AudioseqSegmentRomStart[]; extern u8 _AudioseqSegmentRomEnd[];
extern u8 _AudiotableSegmentRomStart[]; extern u8 _AudiotableSegmentRomEnd[];
extern u8 _link_animetionSegmentRomStart[]; extern u8 _link_animetionSegmentRomEnd[];
extern u8 _icon_item_staticSegmentRomStart[]; extern u8 _icon_item_staticSegmentRomEnd[];
extern u8 _icon_item_24_staticSegmentRomStart[]; extern u8 _icon_item_24_staticSegmentRomEnd[];
extern u8 _do_action_staticSegmentRomStart[]; extern u8 _do_action_staticSegmentRomEnd[];
extern u8 _message_staticSegmentRomStart[]; extern u8 _message_staticSegmentRomEnd[];
extern u8 _message_texture_staticSegmentRomStart[]; extern u8 _message_texture_staticSegmentRomEnd[];
extern u8 _nes_font_staticSegmentRomStart[]; extern u8 _nes_font_staticSegmentRomEnd[];
extern u8 _nes_message_data_staticSegmentRomStart[]; extern u8 _nes_message_data_staticSegmentRomEnd[];
extern u8 _ger_message_data_staticSegmentRomStart[]; extern u8 _ger_message_data_staticSegmentRomEnd[];
extern u8 _fra_message_data_staticSegmentRomStart[]; extern u8 _fra_message_data_staticSegmentRomEnd[];
extern u8 _map_grand_staticSegmentRomStart[]; extern u8 _map_grand_staticSegmentRomEnd[];
extern u8 _codeSegmentRomStart[]; extern u8 _codeSegmentRomEnd[];
extern u8 _codeSegmentBssStart[]; extern u8 _codeSegmentBssEnd[];
extern u8 _ovl_titleSegmentStart[]; extern u8 _ovl_titleSegmentEnd[]; extern u8 _ovl_titleSegmentRomStart[]; extern u8 _ovl_titleSegmentRomEnd[];
extern u8 _ovl_selectSegmentStart[]; extern u8 _ovl_selectSegmentEnd[]; extern u8 _ovl_selectSegmentRomStart[]; extern u8 _ovl_selectSegmentRomEnd[];
extern u8 _ovl_openingSegmentStart[]; extern u8 _ovl_openingSegmentEnd[]; extern u8 _ovl_openingSegmentRomStart[]; extern u8 _ovl_openingSegmentRomEnd[];
extern u8 _ovl_file_chooseSegmentStart[]; extern u8 _ovl_file_chooseSegmentEnd[]; extern u8 _ovl_file_chooseSegmentRomStart[]; extern u8 _ovl_file_chooseSegmentRomEnd[];
extern u8 _ovl_kaleido_scopeSegmentStart[]; extern u8 _ovl_kaleido_scopeSegmentEnd[]; extern u8 _ovl_kaleido_scopeSegmentRomStart[]; extern u8 _ovl_kaleido_scopeSegmentRomEnd[];
extern u8 _ovl_player_actorSegmentStart[]; extern u8 _ovl_player_actorSegmentEnd[]; extern u8 _ovl_player_actorSegmentRomStart[]; extern u8 _ovl_player_actorSegmentRomEnd[];
extern u8 _ovl_map_mark_dataSegmentStart[]; extern u8 _ovl_map_mark_dataSegmentEnd[]; extern u8 _ovl_map_mark_dataSegmentRomStart[]; extern u8 _ovl_map_mark_dataSegmentRomEnd[];
extern u8 _ovl_En_TestSegmentStart[]; extern u8 _ovl_En_TestSegmentEnd[]; extern u8 _ovl_En_TestSegmentRomStart[]; extern u8 _ovl_En_TestSegmentRomEnd[];
extern u8 _ovl_En_GirlASegmentStart[]; extern u8 _ovl_En_GirlASegmentEnd[]; extern u8 _ovl_En_GirlASegmentRomStart[]; extern u8 _ovl_En_GirlASegmentRomEnd[];
extern u8 _ovl_En_PartSegmentStart[]; extern u8 _ovl_En_PartSegmentEnd[]; extern u8 _ovl_En_PartSegmentRomStart[]; extern u8 _ovl_En_PartSegmentRomEnd[];
extern u8 _ovl_En_LightSegmentStart[]; extern u8 _ovl_En_LightSegmentEnd[]; extern u8 _ovl_En_LightSegmentRomStart[]; extern u8 _ovl_En_LightSegmentRomEnd[];
extern u8 _ovl_En_DoorSegmentStart[]; extern u8 _ovl_En_DoorSegmentEnd[]; extern u8 _ovl_En_DoorSegmentRomStart[]; extern u8 _ovl_En_DoorSegmentRomEnd[];
extern u8 _ovl_En_BoxSegmentStart[]; extern u8 _ovl_En_BoxSegmentEnd[]; extern u8 _ovl_En_BoxSegmentRomStart[]; extern u8 _ovl_En_BoxSegmentRomEnd[];
extern u8 _ovl_Bg_Dy_YoseizoSegmentStart[]; extern u8 _ovl_Bg_Dy_YoseizoSegmentEnd[]; extern u8 _ovl_Bg_Dy_YoseizoSegmentRomStart[]; extern u8 _ovl_Bg_Dy_YoseizoSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_FirewallSegmentStart[]; extern u8 _ovl_Bg_Hidan_FirewallSegmentEnd[]; extern u8 _ovl_Bg_Hidan_FirewallSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_FirewallSegmentRomEnd[];
extern u8 _ovl_En_PohSegmentStart[]; extern u8 _ovl_En_PohSegmentEnd[]; extern u8 _ovl_En_PohSegmentRomStart[]; extern u8 _ovl_En_PohSegmentRomEnd[];
extern u8 _ovl_En_OkutaSegmentStart[]; extern u8 _ovl_En_OkutaSegmentEnd[]; extern u8 _ovl_En_OkutaSegmentRomStart[]; extern u8 _ovl_En_OkutaSegmentRomEnd[];
extern u8 _ovl_Bg_Ydan_SpSegmentStart[]; extern u8 _ovl_Bg_Ydan_SpSegmentEnd[]; extern u8 _ovl_Bg_Ydan_SpSegmentRomStart[]; extern u8 _ovl_Bg_Ydan_SpSegmentRomEnd[];
extern u8 _ovl_En_BomSegmentStart[]; extern u8 _ovl_En_BomSegmentEnd[]; extern u8 _ovl_En_BomSegmentRomStart[]; extern u8 _ovl_En_BomSegmentRomEnd[];
extern u8 _ovl_En_WallmasSegmentStart[]; extern u8 _ovl_En_WallmasSegmentEnd[]; extern u8 _ovl_En_WallmasSegmentRomStart[]; extern u8 _ovl_En_WallmasSegmentRomEnd[];
extern u8 _ovl_En_DodongoSegmentStart[]; extern u8 _ovl_En_DodongoSegmentEnd[]; extern u8 _ovl_En_DodongoSegmentRomStart[]; extern u8 _ovl_En_DodongoSegmentRomEnd[];
extern u8 _ovl_En_FireflySegmentStart[]; extern u8 _ovl_En_FireflySegmentEnd[]; extern u8 _ovl_En_FireflySegmentRomStart[]; extern u8 _ovl_En_FireflySegmentRomEnd[];
extern u8 _ovl_En_HorseSegmentStart[]; extern u8 _ovl_En_HorseSegmentEnd[]; extern u8 _ovl_En_HorseSegmentRomStart[]; extern u8 _ovl_En_HorseSegmentRomEnd[];
extern u8 _ovl_En_Item00SegmentStart[]; extern u8 _ovl_En_Item00SegmentEnd[]; extern u8 _ovl_En_Item00SegmentRomStart[]; extern u8 _ovl_En_Item00SegmentRomEnd[];
extern u8 _ovl_En_ArrowSegmentStart[]; extern u8 _ovl_En_ArrowSegmentEnd[]; extern u8 _ovl_En_ArrowSegmentRomStart[]; extern u8 _ovl_En_ArrowSegmentRomEnd[];
extern u8 _ovl_En_ElfSegmentStart[]; extern u8 _ovl_En_ElfSegmentEnd[]; extern u8 _ovl_En_ElfSegmentRomStart[]; extern u8 _ovl_En_ElfSegmentRomEnd[];
extern u8 _ovl_En_NiwSegmentStart[]; extern u8 _ovl_En_NiwSegmentEnd[]; extern u8 _ovl_En_NiwSegmentRomStart[]; extern u8 _ovl_En_NiwSegmentRomEnd[];
extern u8 _ovl_En_TiteSegmentStart[]; extern u8 _ovl_En_TiteSegmentEnd[]; extern u8 _ovl_En_TiteSegmentRomStart[]; extern u8 _ovl_En_TiteSegmentRomEnd[];
extern u8 _ovl_En_ReebaSegmentStart[]; extern u8 _ovl_En_ReebaSegmentEnd[]; extern u8 _ovl_En_ReebaSegmentRomStart[]; extern u8 _ovl_En_ReebaSegmentRomEnd[];
extern u8 _ovl_En_PeehatSegmentStart[]; extern u8 _ovl_En_PeehatSegmentEnd[]; extern u8 _ovl_En_PeehatSegmentRomStart[]; extern u8 _ovl_En_PeehatSegmentRomEnd[];
extern u8 _ovl_En_ButteSegmentStart[]; extern u8 _ovl_En_ButteSegmentEnd[]; extern u8 _ovl_En_ButteSegmentRomStart[]; extern u8 _ovl_En_ButteSegmentRomEnd[];
extern u8 _ovl_En_InsectSegmentStart[]; extern u8 _ovl_En_InsectSegmentEnd[]; extern u8 _ovl_En_InsectSegmentRomStart[]; extern u8 _ovl_En_InsectSegmentRomEnd[];
extern u8 _ovl_En_FishSegmentStart[]; extern u8 _ovl_En_FishSegmentEnd[]; extern u8 _ovl_En_FishSegmentRomStart[]; extern u8 _ovl_En_FishSegmentRomEnd[];
extern u8 _ovl_En_HollSegmentStart[]; extern u8 _ovl_En_HollSegmentEnd[]; extern u8 _ovl_En_HollSegmentRomStart[]; extern u8 _ovl_En_HollSegmentRomEnd[];
extern u8 _ovl_En_Scene_ChangeSegmentStart[]; extern u8 _ovl_En_Scene_ChangeSegmentEnd[]; extern u8 _ovl_En_Scene_ChangeSegmentRomStart[]; extern u8 _ovl_En_Scene_ChangeSegmentRomEnd[];
extern u8 _ovl_En_ZfSegmentStart[]; extern u8 _ovl_En_ZfSegmentEnd[]; extern u8 _ovl_En_ZfSegmentRomStart[]; extern u8 _ovl_En_ZfSegmentRomEnd[];
extern u8 _ovl_En_HataSegmentStart[]; extern u8 _ovl_En_HataSegmentEnd[]; extern u8 _ovl_En_HataSegmentRomStart[]; extern u8 _ovl_En_HataSegmentRomEnd[];
extern u8 _ovl_Boss_DodongoSegmentStart[]; extern u8 _ovl_Boss_DodongoSegmentEnd[]; extern u8 _ovl_Boss_DodongoSegmentRomStart[]; extern u8 _ovl_Boss_DodongoSegmentRomEnd[];
extern u8 _ovl_Boss_GomaSegmentStart[]; extern u8 _ovl_Boss_GomaSegmentEnd[]; extern u8 _ovl_Boss_GomaSegmentRomStart[]; extern u8 _ovl_Boss_GomaSegmentRomEnd[];
extern u8 _ovl_En_Zl1SegmentStart[]; extern u8 _ovl_En_Zl1SegmentEnd[]; extern u8 _ovl_En_Zl1SegmentRomStart[]; extern u8 _ovl_En_Zl1SegmentRomEnd[];
extern u8 _ovl_En_ViewerSegmentStart[]; extern u8 _ovl_En_ViewerSegmentEnd[]; extern u8 _ovl_En_ViewerSegmentRomStart[]; extern u8 _ovl_En_ViewerSegmentRomEnd[];
extern u8 _ovl_En_GomaSegmentStart[]; extern u8 _ovl_En_GomaSegmentEnd[]; extern u8 _ovl_En_GomaSegmentRomStart[]; extern u8 _ovl_En_GomaSegmentRomEnd[];
extern u8 _ovl_Bg_PushboxSegmentStart[]; extern u8 _ovl_Bg_PushboxSegmentEnd[]; extern u8 _ovl_Bg_PushboxSegmentRomStart[]; extern u8 _ovl_Bg_PushboxSegmentRomEnd[];
extern u8 _ovl_En_BubbleSegmentStart[]; extern u8 _ovl_En_BubbleSegmentEnd[]; extern u8 _ovl_En_BubbleSegmentRomStart[]; extern u8 _ovl_En_BubbleSegmentRomEnd[];
extern u8 _ovl_Door_ShutterSegmentStart[]; extern u8 _ovl_Door_ShutterSegmentEnd[]; extern u8 _ovl_Door_ShutterSegmentRomStart[]; extern u8 _ovl_Door_ShutterSegmentRomEnd[];
extern u8 _ovl_En_DodojrSegmentStart[]; extern u8 _ovl_En_DodojrSegmentEnd[]; extern u8 _ovl_En_DodojrSegmentRomStart[]; extern u8 _ovl_En_DodojrSegmentRomEnd[];
extern u8 _ovl_En_BdfireSegmentStart[]; extern u8 _ovl_En_BdfireSegmentEnd[]; extern u8 _ovl_En_BdfireSegmentRomStart[]; extern u8 _ovl_En_BdfireSegmentRomEnd[];
extern u8 _ovl_En_BoomSegmentStart[]; extern u8 _ovl_En_BoomSegmentEnd[]; extern u8 _ovl_En_BoomSegmentRomStart[]; extern u8 _ovl_En_BoomSegmentRomEnd[];
extern u8 _ovl_En_Torch2SegmentStart[]; extern u8 _ovl_En_Torch2SegmentEnd[]; extern u8 _ovl_En_Torch2SegmentRomStart[]; extern u8 _ovl_En_Torch2SegmentRomEnd[];
extern u8 _ovl_En_BiliSegmentStart[]; extern u8 _ovl_En_BiliSegmentEnd[]; extern u8 _ovl_En_BiliSegmentRomStart[]; extern u8 _ovl_En_BiliSegmentRomEnd[];
extern u8 _ovl_En_TpSegmentStart[]; extern u8 _ovl_En_TpSegmentEnd[]; extern u8 _ovl_En_TpSegmentRomStart[]; extern u8 _ovl_En_TpSegmentRomEnd[];
extern u8 _ovl_En_StSegmentStart[]; extern u8 _ovl_En_StSegmentEnd[]; extern u8 _ovl_En_StSegmentRomStart[]; extern u8 _ovl_En_StSegmentRomEnd[];
extern u8 _ovl_En_BwSegmentStart[]; extern u8 _ovl_En_BwSegmentEnd[]; extern u8 _ovl_En_BwSegmentRomStart[]; extern u8 _ovl_En_BwSegmentRomEnd[];
extern u8 _ovl_En_A_ObjSegmentStart[]; extern u8 _ovl_En_A_ObjSegmentEnd[]; extern u8 _ovl_En_A_ObjSegmentRomStart[]; extern u8 _ovl_En_A_ObjSegmentRomEnd[];
extern u8 _ovl_En_EiyerSegmentStart[]; extern u8 _ovl_En_EiyerSegmentEnd[]; extern u8 _ovl_En_EiyerSegmentRomStart[]; extern u8 _ovl_En_EiyerSegmentRomEnd[];
extern u8 _ovl_En_River_SoundSegmentStart[]; extern u8 _ovl_En_River_SoundSegmentEnd[]; extern u8 _ovl_En_River_SoundSegmentRomStart[]; extern u8 _ovl_En_River_SoundSegmentRomEnd[];
extern u8 _ovl_En_Horse_NormalSegmentStart[]; extern u8 _ovl_En_Horse_NormalSegmentEnd[]; extern u8 _ovl_En_Horse_NormalSegmentRomStart[]; extern u8 _ovl_En_Horse_NormalSegmentRomEnd[];
extern u8 _ovl_En_OssanSegmentStart[]; extern u8 _ovl_En_OssanSegmentEnd[]; extern u8 _ovl_En_OssanSegmentRomStart[]; extern u8 _ovl_En_OssanSegmentRomEnd[];
extern u8 _ovl_Bg_TreemouthSegmentStart[]; extern u8 _ovl_Bg_TreemouthSegmentEnd[]; extern u8 _ovl_Bg_TreemouthSegmentRomStart[]; extern u8 _ovl_Bg_TreemouthSegmentRomEnd[];
extern u8 _ovl_Bg_DodoagoSegmentStart[]; extern u8 _ovl_Bg_DodoagoSegmentEnd[]; extern u8 _ovl_Bg_DodoagoSegmentRomStart[]; extern u8 _ovl_Bg_DodoagoSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_DalmSegmentStart[]; extern u8 _ovl_Bg_Hidan_DalmSegmentEnd[]; extern u8 _ovl_Bg_Hidan_DalmSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_DalmSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_HrockSegmentStart[]; extern u8 _ovl_Bg_Hidan_HrockSegmentEnd[]; extern u8 _ovl_Bg_Hidan_HrockSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_HrockSegmentRomEnd[];
extern u8 _ovl_En_Horse_GanonSegmentStart[]; extern u8 _ovl_En_Horse_GanonSegmentEnd[]; extern u8 _ovl_En_Horse_GanonSegmentRomStart[]; extern u8 _ovl_En_Horse_GanonSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_RockSegmentStart[]; extern u8 _ovl_Bg_Hidan_RockSegmentEnd[]; extern u8 _ovl_Bg_Hidan_RockSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_RockSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_RsekizouSegmentStart[]; extern u8 _ovl_Bg_Hidan_RsekizouSegmentEnd[]; extern u8 _ovl_Bg_Hidan_RsekizouSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_RsekizouSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_SekizouSegmentStart[]; extern u8 _ovl_Bg_Hidan_SekizouSegmentEnd[]; extern u8 _ovl_Bg_Hidan_SekizouSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_SekizouSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_SimaSegmentStart[]; extern u8 _ovl_Bg_Hidan_SimaSegmentEnd[]; extern u8 _ovl_Bg_Hidan_SimaSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_SimaSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_SyokuSegmentStart[]; extern u8 _ovl_Bg_Hidan_SyokuSegmentEnd[]; extern u8 _ovl_Bg_Hidan_SyokuSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_SyokuSegmentRomEnd[];
extern u8 _ovl_En_XcSegmentStart[]; extern u8 _ovl_En_XcSegmentEnd[]; extern u8 _ovl_En_XcSegmentRomStart[]; extern u8 _ovl_En_XcSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_CurtainSegmentStart[]; extern u8 _ovl_Bg_Hidan_CurtainSegmentEnd[]; extern u8 _ovl_Bg_Hidan_CurtainSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_CurtainSegmentRomEnd[];
extern u8 _ovl_Bg_Spot00_HanebasiSegmentStart[]; extern u8 _ovl_Bg_Spot00_HanebasiSegmentEnd[]; extern u8 _ovl_Bg_Spot00_HanebasiSegmentRomStart[]; extern u8 _ovl_Bg_Spot00_HanebasiSegmentRomEnd[];
extern u8 _ovl_En_MbSegmentStart[]; extern u8 _ovl_En_MbSegmentEnd[]; extern u8 _ovl_En_MbSegmentRomStart[]; extern u8 _ovl_En_MbSegmentRomEnd[];
extern u8 _ovl_En_BombfSegmentStart[]; extern u8 _ovl_En_BombfSegmentEnd[]; extern u8 _ovl_En_BombfSegmentRomStart[]; extern u8 _ovl_En_BombfSegmentRomEnd[];
extern u8 _ovl_En_Zl2SegmentStart[]; extern u8 _ovl_En_Zl2SegmentEnd[]; extern u8 _ovl_En_Zl2SegmentRomStart[]; extern u8 _ovl_En_Zl2SegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_FsliftSegmentStart[]; extern u8 _ovl_Bg_Hidan_FsliftSegmentEnd[]; extern u8 _ovl_Bg_Hidan_FsliftSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_FsliftSegmentRomEnd[];
extern u8 _ovl_En_OE2SegmentStart[]; extern u8 _ovl_En_OE2SegmentEnd[]; extern u8 _ovl_En_OE2SegmentRomStart[]; extern u8 _ovl_En_OE2SegmentRomEnd[];
extern u8 _ovl_Bg_Ydan_HasiSegmentStart[]; extern u8 _ovl_Bg_Ydan_HasiSegmentEnd[]; extern u8 _ovl_Bg_Ydan_HasiSegmentRomStart[]; extern u8 _ovl_Bg_Ydan_HasiSegmentRomEnd[];
extern u8 _ovl_Bg_Ydan_MarutaSegmentStart[]; extern u8 _ovl_Bg_Ydan_MarutaSegmentEnd[]; extern u8 _ovl_Bg_Ydan_MarutaSegmentRomStart[]; extern u8 _ovl_Bg_Ydan_MarutaSegmentRomEnd[];
extern u8 _ovl_Boss_GanondrofSegmentStart[]; extern u8 _ovl_Boss_GanondrofSegmentEnd[]; extern u8 _ovl_Boss_GanondrofSegmentRomStart[]; extern u8 _ovl_Boss_GanondrofSegmentRomEnd[];
extern u8 _ovl_En_AmSegmentStart[]; extern u8 _ovl_En_AmSegmentEnd[]; extern u8 _ovl_En_AmSegmentRomStart[]; extern u8 _ovl_En_AmSegmentRomEnd[];
extern u8 _ovl_En_DekubabaSegmentStart[]; extern u8 _ovl_En_DekubabaSegmentEnd[]; extern u8 _ovl_En_DekubabaSegmentRomStart[]; extern u8 _ovl_En_DekubabaSegmentRomEnd[];
extern u8 _ovl_En_M_Fire1SegmentStart[]; extern u8 _ovl_En_M_Fire1SegmentEnd[]; extern u8 _ovl_En_M_Fire1SegmentRomStart[]; extern u8 _ovl_En_M_Fire1SegmentRomEnd[];
extern u8 _ovl_En_M_ThunderSegmentStart[]; extern u8 _ovl_En_M_ThunderSegmentEnd[]; extern u8 _ovl_En_M_ThunderSegmentRomStart[]; extern u8 _ovl_En_M_ThunderSegmentRomEnd[];
extern u8 _ovl_Bg_Ddan_JdSegmentStart[]; extern u8 _ovl_Bg_Ddan_JdSegmentEnd[]; extern u8 _ovl_Bg_Ddan_JdSegmentRomStart[]; extern u8 _ovl_Bg_Ddan_JdSegmentRomEnd[];
extern u8 _ovl_Bg_BreakwallSegmentStart[]; extern u8 _ovl_Bg_BreakwallSegmentEnd[]; extern u8 _ovl_Bg_BreakwallSegmentRomStart[]; extern u8 _ovl_Bg_BreakwallSegmentRomEnd[];
extern u8 _ovl_En_JjSegmentStart[]; extern u8 _ovl_En_JjSegmentEnd[]; extern u8 _ovl_En_JjSegmentRomStart[]; extern u8 _ovl_En_JjSegmentRomEnd[];
extern u8 _ovl_En_Horse_ZeldaSegmentStart[]; extern u8 _ovl_En_Horse_ZeldaSegmentEnd[]; extern u8 _ovl_En_Horse_ZeldaSegmentRomStart[]; extern u8 _ovl_En_Horse_ZeldaSegmentRomEnd[];
extern u8 _ovl_Bg_Ddan_KdSegmentStart[]; extern u8 _ovl_Bg_Ddan_KdSegmentEnd[]; extern u8 _ovl_Bg_Ddan_KdSegmentRomStart[]; extern u8 _ovl_Bg_Ddan_KdSegmentRomEnd[];
extern u8 _ovl_Door_Warp1SegmentStart[]; extern u8 _ovl_Door_Warp1SegmentEnd[]; extern u8 _ovl_Door_Warp1SegmentRomStart[]; extern u8 _ovl_Door_Warp1SegmentRomEnd[];
extern u8 _ovl_Obj_SyokudaiSegmentStart[]; extern u8 _ovl_Obj_SyokudaiSegmentEnd[]; extern u8 _ovl_Obj_SyokudaiSegmentRomStart[]; extern u8 _ovl_Obj_SyokudaiSegmentRomEnd[];
extern u8 _ovl_Item_B_HeartSegmentStart[]; extern u8 _ovl_Item_B_HeartSegmentEnd[]; extern u8 _ovl_Item_B_HeartSegmentRomStart[]; extern u8 _ovl_Item_B_HeartSegmentRomEnd[];
extern u8 _ovl_En_DekunutsSegmentStart[]; extern u8 _ovl_En_DekunutsSegmentEnd[]; extern u8 _ovl_En_DekunutsSegmentRomStart[]; extern u8 _ovl_En_DekunutsSegmentRomEnd[];
extern u8 _ovl_Bg_Menkuri_KaitenSegmentStart[]; extern u8 _ovl_Bg_Menkuri_KaitenSegmentEnd[]; extern u8 _ovl_Bg_Menkuri_KaitenSegmentRomStart[]; extern u8 _ovl_Bg_Menkuri_KaitenSegmentRomEnd[];
extern u8 _ovl_Bg_Menkuri_EyeSegmentStart[]; extern u8 _ovl_Bg_Menkuri_EyeSegmentEnd[]; extern u8 _ovl_Bg_Menkuri_EyeSegmentRomStart[]; extern u8 _ovl_Bg_Menkuri_EyeSegmentRomEnd[];
extern u8 _ovl_En_ValiSegmentStart[]; extern u8 _ovl_En_ValiSegmentEnd[]; extern u8 _ovl_En_ValiSegmentRomStart[]; extern u8 _ovl_En_ValiSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_MovebgSegmentStart[]; extern u8 _ovl_Bg_Mizu_MovebgSegmentEnd[]; extern u8 _ovl_Bg_Mizu_MovebgSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_MovebgSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_WaterSegmentStart[]; extern u8 _ovl_Bg_Mizu_WaterSegmentEnd[]; extern u8 _ovl_Bg_Mizu_WaterSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_WaterSegmentRomEnd[];
extern u8 _ovl_Arms_HookSegmentStart[]; extern u8 _ovl_Arms_HookSegmentEnd[]; extern u8 _ovl_Arms_HookSegmentRomStart[]; extern u8 _ovl_Arms_HookSegmentRomEnd[];
extern u8 _ovl_En_fHGSegmentStart[]; extern u8 _ovl_En_fHGSegmentEnd[]; extern u8 _ovl_En_fHGSegmentRomStart[]; extern u8 _ovl_En_fHGSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_HineriSegmentStart[]; extern u8 _ovl_Bg_Mori_HineriSegmentEnd[]; extern u8 _ovl_Bg_Mori_HineriSegmentRomStart[]; extern u8 _ovl_Bg_Mori_HineriSegmentRomEnd[];
extern u8 _ovl_En_BbSegmentStart[]; extern u8 _ovl_En_BbSegmentEnd[]; extern u8 _ovl_En_BbSegmentRomStart[]; extern u8 _ovl_En_BbSegmentRomEnd[];
extern u8 _ovl_Bg_Toki_HikariSegmentStart[]; extern u8 _ovl_Bg_Toki_HikariSegmentEnd[]; extern u8 _ovl_Bg_Toki_HikariSegmentRomStart[]; extern u8 _ovl_Bg_Toki_HikariSegmentRomEnd[];
extern u8 _ovl_En_YukabyunSegmentStart[]; extern u8 _ovl_En_YukabyunSegmentEnd[]; extern u8 _ovl_En_YukabyunSegmentRomStart[]; extern u8 _ovl_En_YukabyunSegmentRomEnd[];
extern u8 _ovl_Bg_Toki_SwdSegmentStart[]; extern u8 _ovl_Bg_Toki_SwdSegmentEnd[]; extern u8 _ovl_Bg_Toki_SwdSegmentRomStart[]; extern u8 _ovl_Bg_Toki_SwdSegmentRomEnd[];
extern u8 _ovl_En_Fhg_FireSegmentStart[]; extern u8 _ovl_En_Fhg_FireSegmentEnd[]; extern u8 _ovl_En_Fhg_FireSegmentRomStart[]; extern u8 _ovl_En_Fhg_FireSegmentRomEnd[];
extern u8 _ovl_Bg_MjinSegmentStart[]; extern u8 _ovl_Bg_MjinSegmentEnd[]; extern u8 _ovl_Bg_MjinSegmentRomStart[]; extern u8 _ovl_Bg_MjinSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_KousiSegmentStart[]; extern u8 _ovl_Bg_Hidan_KousiSegmentEnd[]; extern u8 _ovl_Bg_Hidan_KousiSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_KousiSegmentRomEnd[];
extern u8 _ovl_Door_TokiSegmentStart[]; extern u8 _ovl_Door_TokiSegmentEnd[]; extern u8 _ovl_Door_TokiSegmentRomStart[]; extern u8 _ovl_Door_TokiSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_HamstepSegmentStart[]; extern u8 _ovl_Bg_Hidan_HamstepSegmentEnd[]; extern u8 _ovl_Bg_Hidan_HamstepSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_HamstepSegmentRomEnd[];
extern u8 _ovl_En_BirdSegmentStart[]; extern u8 _ovl_En_BirdSegmentEnd[]; extern u8 _ovl_En_BirdSegmentRomStart[]; extern u8 _ovl_En_BirdSegmentRomEnd[];
extern u8 _ovl_En_Wood02SegmentStart[]; extern u8 _ovl_En_Wood02SegmentEnd[]; extern u8 _ovl_En_Wood02SegmentRomStart[]; extern u8 _ovl_En_Wood02SegmentRomEnd[];
extern u8 _ovl_En_LightboxSegmentStart[]; extern u8 _ovl_En_LightboxSegmentEnd[]; extern u8 _ovl_En_LightboxSegmentRomStart[]; extern u8 _ovl_En_LightboxSegmentRomEnd[];
extern u8 _ovl_En_Pu_boxSegmentStart[]; extern u8 _ovl_En_Pu_boxSegmentEnd[]; extern u8 _ovl_En_Pu_boxSegmentRomStart[]; extern u8 _ovl_En_Pu_boxSegmentRomEnd[];
extern u8 _ovl_En_TrapSegmentStart[]; extern u8 _ovl_En_TrapSegmentEnd[]; extern u8 _ovl_En_TrapSegmentRomStart[]; extern u8 _ovl_En_TrapSegmentRomEnd[];
extern u8 _ovl_En_Arow_TrapSegmentStart[]; extern u8 _ovl_En_Arow_TrapSegmentEnd[]; extern u8 _ovl_En_Arow_TrapSegmentRomStart[]; extern u8 _ovl_En_Arow_TrapSegmentRomEnd[];
extern u8 _ovl_En_VaseSegmentStart[]; extern u8 _ovl_En_VaseSegmentEnd[]; extern u8 _ovl_En_VaseSegmentRomStart[]; extern u8 _ovl_En_VaseSegmentRomEnd[];
extern u8 _ovl_En_TaSegmentStart[]; extern u8 _ovl_En_TaSegmentEnd[]; extern u8 _ovl_En_TaSegmentRomStart[]; extern u8 _ovl_En_TaSegmentRomEnd[];
extern u8 _ovl_En_TkSegmentStart[]; extern u8 _ovl_En_TkSegmentEnd[]; extern u8 _ovl_En_TkSegmentRomStart[]; extern u8 _ovl_En_TkSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_BigstSegmentStart[]; extern u8 _ovl_Bg_Mori_BigstSegmentEnd[]; extern u8 _ovl_Bg_Mori_BigstSegmentRomStart[]; extern u8 _ovl_Bg_Mori_BigstSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_ElevatorSegmentStart[]; extern u8 _ovl_Bg_Mori_ElevatorSegmentEnd[]; extern u8 _ovl_Bg_Mori_ElevatorSegmentRomStart[]; extern u8 _ovl_Bg_Mori_ElevatorSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_KaitenkabeSegmentStart[]; extern u8 _ovl_Bg_Mori_KaitenkabeSegmentEnd[]; extern u8 _ovl_Bg_Mori_KaitenkabeSegmentRomStart[]; extern u8 _ovl_Bg_Mori_KaitenkabeSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_RakkatenjoSegmentStart[]; extern u8 _ovl_Bg_Mori_RakkatenjoSegmentEnd[]; extern u8 _ovl_Bg_Mori_RakkatenjoSegmentRomStart[]; extern u8 _ovl_Bg_Mori_RakkatenjoSegmentRomEnd[];
extern u8 _ovl_En_VmSegmentStart[]; extern u8 _ovl_En_VmSegmentEnd[]; extern u8 _ovl_En_VmSegmentRomStart[]; extern u8 _ovl_En_VmSegmentRomEnd[];
extern u8 _ovl_Demo_EffectSegmentStart[]; extern u8 _ovl_Demo_EffectSegmentEnd[]; extern u8 _ovl_Demo_EffectSegmentRomStart[]; extern u8 _ovl_Demo_EffectSegmentRomEnd[];
extern u8 _ovl_Demo_KankyoSegmentStart[]; extern u8 _ovl_Demo_KankyoSegmentEnd[]; extern u8 _ovl_Demo_KankyoSegmentRomStart[]; extern u8 _ovl_Demo_KankyoSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_FwbigSegmentStart[]; extern u8 _ovl_Bg_Hidan_FwbigSegmentEnd[]; extern u8 _ovl_Bg_Hidan_FwbigSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_FwbigSegmentRomEnd[];
extern u8 _ovl_En_FloormasSegmentStart[]; extern u8 _ovl_En_FloormasSegmentEnd[]; extern u8 _ovl_En_FloormasSegmentRomStart[]; extern u8 _ovl_En_FloormasSegmentRomEnd[];
extern u8 _ovl_En_Heishi1SegmentStart[]; extern u8 _ovl_En_Heishi1SegmentEnd[]; extern u8 _ovl_En_Heishi1SegmentRomStart[]; extern u8 _ovl_En_Heishi1SegmentRomEnd[];
extern u8 _ovl_En_RdSegmentStart[]; extern u8 _ovl_En_RdSegmentEnd[]; extern u8 _ovl_En_RdSegmentRomStart[]; extern u8 _ovl_En_RdSegmentRomEnd[];
extern u8 _ovl_En_Po_SistersSegmentStart[]; extern u8 _ovl_En_Po_SistersSegmentEnd[]; extern u8 _ovl_En_Po_SistersSegmentRomStart[]; extern u8 _ovl_En_Po_SistersSegmentRomEnd[];
extern u8 _ovl_Bg_Heavy_BlockSegmentStart[]; extern u8 _ovl_Bg_Heavy_BlockSegmentEnd[]; extern u8 _ovl_Bg_Heavy_BlockSegmentRomStart[]; extern u8 _ovl_Bg_Heavy_BlockSegmentRomEnd[];
extern u8 _ovl_Bg_Po_EventSegmentStart[]; extern u8 _ovl_Bg_Po_EventSegmentEnd[]; extern u8 _ovl_Bg_Po_EventSegmentRomStart[]; extern u8 _ovl_Bg_Po_EventSegmentRomEnd[];
extern u8 _ovl_Obj_MureSegmentStart[]; extern u8 _ovl_Obj_MureSegmentEnd[]; extern u8 _ovl_Obj_MureSegmentRomStart[]; extern u8 _ovl_Obj_MureSegmentRomEnd[];
extern u8 _ovl_En_SwSegmentStart[]; extern u8 _ovl_En_SwSegmentEnd[]; extern u8 _ovl_En_SwSegmentRomStart[]; extern u8 _ovl_En_SwSegmentRomEnd[];
extern u8 _ovl_Boss_FdSegmentStart[]; extern u8 _ovl_Boss_FdSegmentEnd[]; extern u8 _ovl_Boss_FdSegmentRomStart[]; extern u8 _ovl_Boss_FdSegmentRomEnd[];
extern u8 _ovl_Object_KankyoSegmentStart[]; extern u8 _ovl_Object_KankyoSegmentEnd[]; extern u8 _ovl_Object_KankyoSegmentRomStart[]; extern u8 _ovl_Object_KankyoSegmentRomEnd[];
extern u8 _ovl_En_DuSegmentStart[]; extern u8 _ovl_En_DuSegmentEnd[]; extern u8 _ovl_En_DuSegmentRomStart[]; extern u8 _ovl_En_DuSegmentRomEnd[];
extern u8 _ovl_En_FdSegmentStart[]; extern u8 _ovl_En_FdSegmentEnd[]; extern u8 _ovl_En_FdSegmentRomStart[]; extern u8 _ovl_En_FdSegmentRomEnd[];
extern u8 _ovl_En_Horse_Link_ChildSegmentStart[]; extern u8 _ovl_En_Horse_Link_ChildSegmentEnd[]; extern u8 _ovl_En_Horse_Link_ChildSegmentRomStart[]; extern u8 _ovl_En_Horse_Link_ChildSegmentRomEnd[];
extern u8 _ovl_Door_AnaSegmentStart[]; extern u8 _ovl_Door_AnaSegmentEnd[]; extern u8 _ovl_Door_AnaSegmentRomStart[]; extern u8 _ovl_Door_AnaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot02_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Spot02_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Spot02_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Spot02_ObjectsSegmentRomEnd[];
extern u8 _ovl_Bg_HakaSegmentStart[]; extern u8 _ovl_Bg_HakaSegmentEnd[]; extern u8 _ovl_Bg_HakaSegmentRomStart[]; extern u8 _ovl_Bg_HakaSegmentRomEnd[];
extern u8 _ovl_Magic_WindSegmentStart[]; extern u8 _ovl_Magic_WindSegmentEnd[]; extern u8 _ovl_Magic_WindSegmentRomStart[]; extern u8 _ovl_Magic_WindSegmentRomEnd[];
extern u8 _ovl_Magic_FireSegmentStart[]; extern u8 _ovl_Magic_FireSegmentEnd[]; extern u8 _ovl_Magic_FireSegmentRomStart[]; extern u8 _ovl_Magic_FireSegmentRomEnd[];
extern u8 _ovl_En_Ru1SegmentStart[]; extern u8 _ovl_En_Ru1SegmentEnd[]; extern u8 _ovl_En_Ru1SegmentRomStart[]; extern u8 _ovl_En_Ru1SegmentRomEnd[];
extern u8 _ovl_Boss_Fd2SegmentStart[]; extern u8 _ovl_Boss_Fd2SegmentEnd[]; extern u8 _ovl_Boss_Fd2SegmentRomStart[]; extern u8 _ovl_Boss_Fd2SegmentRomEnd[];
extern u8 _ovl_En_Fd_FireSegmentStart[]; extern u8 _ovl_En_Fd_FireSegmentEnd[]; extern u8 _ovl_En_Fd_FireSegmentRomStart[]; extern u8 _ovl_En_Fd_FireSegmentRomEnd[];
extern u8 _ovl_En_DhSegmentStart[]; extern u8 _ovl_En_DhSegmentEnd[]; extern u8 _ovl_En_DhSegmentRomStart[]; extern u8 _ovl_En_DhSegmentRomEnd[];
extern u8 _ovl_En_DhaSegmentStart[]; extern u8 _ovl_En_DhaSegmentEnd[]; extern u8 _ovl_En_DhaSegmentRomStart[]; extern u8 _ovl_En_DhaSegmentRomEnd[];
extern u8 _ovl_En_RlSegmentStart[]; extern u8 _ovl_En_RlSegmentEnd[]; extern u8 _ovl_En_RlSegmentRomStart[]; extern u8 _ovl_En_RlSegmentRomEnd[];
extern u8 _ovl_En_Encount1SegmentStart[]; extern u8 _ovl_En_Encount1SegmentEnd[]; extern u8 _ovl_En_Encount1SegmentRomStart[]; extern u8 _ovl_En_Encount1SegmentRomEnd[];
extern u8 _ovl_Demo_DuSegmentStart[]; extern u8 _ovl_Demo_DuSegmentEnd[]; extern u8 _ovl_Demo_DuSegmentRomStart[]; extern u8 _ovl_Demo_DuSegmentRomEnd[];
extern u8 _ovl_Demo_ImSegmentStart[]; extern u8 _ovl_Demo_ImSegmentEnd[]; extern u8 _ovl_Demo_ImSegmentRomStart[]; extern u8 _ovl_Demo_ImSegmentRomEnd[];
extern u8 _ovl_Demo_Tre_LgtSegmentStart[]; extern u8 _ovl_Demo_Tre_LgtSegmentEnd[]; extern u8 _ovl_Demo_Tre_LgtSegmentRomStart[]; extern u8 _ovl_Demo_Tre_LgtSegmentRomEnd[];
extern u8 _ovl_En_FwSegmentStart[]; extern u8 _ovl_En_FwSegmentEnd[]; extern u8 _ovl_En_FwSegmentRomStart[]; extern u8 _ovl_En_FwSegmentRomEnd[];
extern u8 _ovl_Bg_Vb_SimaSegmentStart[]; extern u8 _ovl_Bg_Vb_SimaSegmentEnd[]; extern u8 _ovl_Bg_Vb_SimaSegmentRomStart[]; extern u8 _ovl_Bg_Vb_SimaSegmentRomEnd[];
extern u8 _ovl_En_Vb_BallSegmentStart[]; extern u8 _ovl_En_Vb_BallSegmentEnd[]; extern u8 _ovl_En_Vb_BallSegmentRomStart[]; extern u8 _ovl_En_Vb_BallSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_MeganeSegmentStart[]; extern u8 _ovl_Bg_Haka_MeganeSegmentEnd[]; extern u8 _ovl_Bg_Haka_MeganeSegmentRomStart[]; extern u8 _ovl_Bg_Haka_MeganeSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_MeganeBGSegmentStart[]; extern u8 _ovl_Bg_Haka_MeganeBGSegmentEnd[]; extern u8 _ovl_Bg_Haka_MeganeBGSegmentRomStart[]; extern u8 _ovl_Bg_Haka_MeganeBGSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_ShipSegmentStart[]; extern u8 _ovl_Bg_Haka_ShipSegmentEnd[]; extern u8 _ovl_Bg_Haka_ShipSegmentRomStart[]; extern u8 _ovl_Bg_Haka_ShipSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_SgamiSegmentStart[]; extern u8 _ovl_Bg_Haka_SgamiSegmentEnd[]; extern u8 _ovl_Bg_Haka_SgamiSegmentRomStart[]; extern u8 _ovl_Bg_Haka_SgamiSegmentRomEnd[];
extern u8 _ovl_En_Heishi2SegmentStart[]; extern u8 _ovl_En_Heishi2SegmentEnd[]; extern u8 _ovl_En_Heishi2SegmentRomStart[]; extern u8 _ovl_En_Heishi2SegmentRomEnd[];
extern u8 _ovl_En_Encount2SegmentStart[]; extern u8 _ovl_En_Encount2SegmentEnd[]; extern u8 _ovl_En_Encount2SegmentRomStart[]; extern u8 _ovl_En_Encount2SegmentRomEnd[];
extern u8 _ovl_En_Fire_RockSegmentStart[]; extern u8 _ovl_En_Fire_RockSegmentEnd[]; extern u8 _ovl_En_Fire_RockSegmentRomStart[]; extern u8 _ovl_En_Fire_RockSegmentRomEnd[];
extern u8 _ovl_En_BrobSegmentStart[]; extern u8 _ovl_En_BrobSegmentEnd[]; extern u8 _ovl_En_BrobSegmentRomStart[]; extern u8 _ovl_En_BrobSegmentRomEnd[];
extern u8 _ovl_Mir_RaySegmentStart[]; extern u8 _ovl_Mir_RaySegmentEnd[]; extern u8 _ovl_Mir_RaySegmentRomStart[]; extern u8 _ovl_Mir_RaySegmentRomEnd[];
extern u8 _ovl_Bg_Spot09_ObjSegmentStart[]; extern u8 _ovl_Bg_Spot09_ObjSegmentEnd[]; extern u8 _ovl_Bg_Spot09_ObjSegmentRomStart[]; extern u8 _ovl_Bg_Spot09_ObjSegmentRomEnd[];
extern u8 _ovl_Bg_Spot18_ObjSegmentStart[]; extern u8 _ovl_Bg_Spot18_ObjSegmentEnd[]; extern u8 _ovl_Bg_Spot18_ObjSegmentRomStart[]; extern u8 _ovl_Bg_Spot18_ObjSegmentRomEnd[];
extern u8 _ovl_Boss_VaSegmentStart[]; extern u8 _ovl_Boss_VaSegmentEnd[]; extern u8 _ovl_Boss_VaSegmentRomStart[]; extern u8 _ovl_Boss_VaSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_TuboSegmentStart[]; extern u8 _ovl_Bg_Haka_TuboSegmentEnd[]; extern u8 _ovl_Bg_Haka_TuboSegmentRomStart[]; extern u8 _ovl_Bg_Haka_TuboSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_TrapSegmentStart[]; extern u8 _ovl_Bg_Haka_TrapSegmentEnd[]; extern u8 _ovl_Bg_Haka_TrapSegmentRomStart[]; extern u8 _ovl_Bg_Haka_TrapSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_HutaSegmentStart[]; extern u8 _ovl_Bg_Haka_HutaSegmentEnd[]; extern u8 _ovl_Bg_Haka_HutaSegmentRomStart[]; extern u8 _ovl_Bg_Haka_HutaSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_ZouSegmentStart[]; extern u8 _ovl_Bg_Haka_ZouSegmentEnd[]; extern u8 _ovl_Bg_Haka_ZouSegmentRomStart[]; extern u8 _ovl_Bg_Haka_ZouSegmentRomEnd[];
extern u8 _ovl_Bg_Spot17_FunenSegmentStart[]; extern u8 _ovl_Bg_Spot17_FunenSegmentEnd[]; extern u8 _ovl_Bg_Spot17_FunenSegmentRomStart[]; extern u8 _ovl_Bg_Spot17_FunenSegmentRomEnd[];
extern u8 _ovl_En_Syateki_ItmSegmentStart[]; extern u8 _ovl_En_Syateki_ItmSegmentEnd[]; extern u8 _ovl_En_Syateki_ItmSegmentRomStart[]; extern u8 _ovl_En_Syateki_ItmSegmentRomEnd[];
extern u8 _ovl_En_Syateki_ManSegmentStart[]; extern u8 _ovl_En_Syateki_ManSegmentEnd[]; extern u8 _ovl_En_Syateki_ManSegmentRomStart[]; extern u8 _ovl_En_Syateki_ManSegmentRomEnd[];
extern u8 _ovl_En_TanaSegmentStart[]; extern u8 _ovl_En_TanaSegmentEnd[]; extern u8 _ovl_En_TanaSegmentRomStart[]; extern u8 _ovl_En_TanaSegmentRomEnd[];
extern u8 _ovl_En_NbSegmentStart[]; extern u8 _ovl_En_NbSegmentEnd[]; extern u8 _ovl_En_NbSegmentRomStart[]; extern u8 _ovl_En_NbSegmentRomEnd[];
extern u8 _ovl_Boss_MoSegmentStart[]; extern u8 _ovl_Boss_MoSegmentEnd[]; extern u8 _ovl_Boss_MoSegmentRomStart[]; extern u8 _ovl_Boss_MoSegmentRomEnd[];
extern u8 _ovl_En_SbSegmentStart[]; extern u8 _ovl_En_SbSegmentEnd[]; extern u8 _ovl_En_SbSegmentRomStart[]; extern u8 _ovl_En_SbSegmentRomEnd[];
extern u8 _ovl_En_BigokutaSegmentStart[]; extern u8 _ovl_En_BigokutaSegmentEnd[]; extern u8 _ovl_En_BigokutaSegmentRomStart[]; extern u8 _ovl_En_BigokutaSegmentRomEnd[];
extern u8 _ovl_En_KarebabaSegmentStart[]; extern u8 _ovl_En_KarebabaSegmentEnd[]; extern u8 _ovl_En_KarebabaSegmentRomStart[]; extern u8 _ovl_En_KarebabaSegmentRomEnd[];
extern u8 _ovl_Bg_Bdan_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Bdan_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Bdan_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Bdan_ObjectsSegmentRomEnd[];
extern u8 _ovl_Demo_SaSegmentStart[]; extern u8 _ovl_Demo_SaSegmentEnd[]; extern u8 _ovl_Demo_SaSegmentRomStart[]; extern u8 _ovl_Demo_SaSegmentRomEnd[];
extern u8 _ovl_Demo_GoSegmentStart[]; extern u8 _ovl_Demo_GoSegmentEnd[]; extern u8 _ovl_Demo_GoSegmentRomStart[]; extern u8 _ovl_Demo_GoSegmentRomEnd[];
extern u8 _ovl_En_InSegmentStart[]; extern u8 _ovl_En_InSegmentEnd[]; extern u8 _ovl_En_InSegmentRomStart[]; extern u8 _ovl_En_InSegmentRomEnd[];
extern u8 _ovl_En_TrSegmentStart[]; extern u8 _ovl_En_TrSegmentEnd[]; extern u8 _ovl_En_TrSegmentRomStart[]; extern u8 _ovl_En_TrSegmentRomEnd[];
extern u8 _ovl_Bg_Spot16_BombstoneSegmentStart[]; extern u8 _ovl_Bg_Spot16_BombstoneSegmentEnd[]; extern u8 _ovl_Bg_Spot16_BombstoneSegmentRomStart[]; extern u8 _ovl_Bg_Spot16_BombstoneSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_KowarerukabeSegmentStart[]; extern u8 _ovl_Bg_Hidan_KowarerukabeSegmentEnd[]; extern u8 _ovl_Bg_Hidan_KowarerukabeSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_KowarerukabeSegmentRomEnd[];
extern u8 _ovl_Bg_BombwallSegmentStart[]; extern u8 _ovl_Bg_BombwallSegmentEnd[]; extern u8 _ovl_Bg_BombwallSegmentRomStart[]; extern u8 _ovl_Bg_BombwallSegmentRomEnd[];
extern u8 _ovl_Bg_Spot08_IceblockSegmentStart[]; extern u8 _ovl_Bg_Spot08_IceblockSegmentEnd[]; extern u8 _ovl_Bg_Spot08_IceblockSegmentRomStart[]; extern u8 _ovl_Bg_Spot08_IceblockSegmentRomEnd[];
extern u8 _ovl_En_Ru2SegmentStart[]; extern u8 _ovl_En_Ru2SegmentEnd[]; extern u8 _ovl_En_Ru2SegmentRomStart[]; extern u8 _ovl_En_Ru2SegmentRomEnd[];
extern u8 _ovl_Obj_DekujrSegmentStart[]; extern u8 _ovl_Obj_DekujrSegmentEnd[]; extern u8 _ovl_Obj_DekujrSegmentRomStart[]; extern u8 _ovl_Obj_DekujrSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_UzuSegmentStart[]; extern u8 _ovl_Bg_Mizu_UzuSegmentEnd[]; extern u8 _ovl_Bg_Mizu_UzuSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_UzuSegmentRomEnd[];
extern u8 _ovl_Bg_Spot06_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Spot06_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Spot06_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Spot06_ObjectsSegmentRomEnd[];
extern u8 _ovl_Bg_Ice_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Ice_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Ice_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Ice_ObjectsSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_WaterSegmentStart[]; extern u8 _ovl_Bg_Haka_WaterSegmentEnd[]; extern u8 _ovl_Bg_Haka_WaterSegmentRomStart[]; extern u8 _ovl_Bg_Haka_WaterSegmentRomEnd[];
extern u8 _ovl_En_Ma2SegmentStart[]; extern u8 _ovl_En_Ma2SegmentEnd[]; extern u8 _ovl_En_Ma2SegmentRomStart[]; extern u8 _ovl_En_Ma2SegmentRomEnd[];
extern u8 _ovl_En_Bom_ChuSegmentStart[]; extern u8 _ovl_En_Bom_ChuSegmentEnd[]; extern u8 _ovl_En_Bom_ChuSegmentRomStart[]; extern u8 _ovl_En_Bom_ChuSegmentRomEnd[];
extern u8 _ovl_En_Horse_Game_CheckSegmentStart[]; extern u8 _ovl_En_Horse_Game_CheckSegmentEnd[]; extern u8 _ovl_En_Horse_Game_CheckSegmentRomStart[]; extern u8 _ovl_En_Horse_Game_CheckSegmentRomEnd[];
extern u8 _ovl_Boss_TwSegmentStart[]; extern u8 _ovl_Boss_TwSegmentEnd[]; extern u8 _ovl_Boss_TwSegmentRomStart[]; extern u8 _ovl_Boss_TwSegmentRomEnd[];
extern u8 _ovl_En_RrSegmentStart[]; extern u8 _ovl_En_RrSegmentEnd[]; extern u8 _ovl_En_RrSegmentRomStart[]; extern u8 _ovl_En_RrSegmentRomEnd[];
extern u8 _ovl_En_BaSegmentStart[]; extern u8 _ovl_En_BaSegmentEnd[]; extern u8 _ovl_En_BaSegmentRomStart[]; extern u8 _ovl_En_BaSegmentRomEnd[];
extern u8 _ovl_En_BxSegmentStart[]; extern u8 _ovl_En_BxSegmentEnd[]; extern u8 _ovl_En_BxSegmentRomStart[]; extern u8 _ovl_En_BxSegmentRomEnd[];
extern u8 _ovl_En_AnubiceSegmentStart[]; extern u8 _ovl_En_AnubiceSegmentEnd[]; extern u8 _ovl_En_AnubiceSegmentRomStart[]; extern u8 _ovl_En_AnubiceSegmentRomEnd[];
extern u8 _ovl_En_Anubice_FireSegmentStart[]; extern u8 _ovl_En_Anubice_FireSegmentEnd[]; extern u8 _ovl_En_Anubice_FireSegmentRomStart[]; extern u8 _ovl_En_Anubice_FireSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_HashigoSegmentStart[]; extern u8 _ovl_Bg_Mori_HashigoSegmentEnd[]; extern u8 _ovl_Bg_Mori_HashigoSegmentRomStart[]; extern u8 _ovl_Bg_Mori_HashigoSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_Hashira4SegmentStart[]; extern u8 _ovl_Bg_Mori_Hashira4SegmentEnd[]; extern u8 _ovl_Bg_Mori_Hashira4SegmentRomStart[]; extern u8 _ovl_Bg_Mori_Hashira4SegmentRomEnd[];
extern u8 _ovl_Bg_Mori_IdomizuSegmentStart[]; extern u8 _ovl_Bg_Mori_IdomizuSegmentEnd[]; extern u8 _ovl_Bg_Mori_IdomizuSegmentRomStart[]; extern u8 _ovl_Bg_Mori_IdomizuSegmentRomEnd[];
extern u8 _ovl_Bg_Spot16_DoughnutSegmentStart[]; extern u8 _ovl_Bg_Spot16_DoughnutSegmentEnd[]; extern u8 _ovl_Bg_Spot16_DoughnutSegmentRomStart[]; extern u8 _ovl_Bg_Spot16_DoughnutSegmentRomEnd[];
extern u8 _ovl_Bg_Bdan_SwitchSegmentStart[]; extern u8 _ovl_Bg_Bdan_SwitchSegmentEnd[]; extern u8 _ovl_Bg_Bdan_SwitchSegmentRomStart[]; extern u8 _ovl_Bg_Bdan_SwitchSegmentRomEnd[];
extern u8 _ovl_En_Ma1SegmentStart[]; extern u8 _ovl_En_Ma1SegmentEnd[]; extern u8 _ovl_En_Ma1SegmentRomStart[]; extern u8 _ovl_En_Ma1SegmentRomEnd[];
extern u8 _ovl_Boss_GanonSegmentStart[]; extern u8 _ovl_Boss_GanonSegmentEnd[]; extern u8 _ovl_Boss_GanonSegmentRomStart[]; extern u8 _ovl_Boss_GanonSegmentRomEnd[];
extern u8 _ovl_Boss_SstSegmentStart[]; extern u8 _ovl_Boss_SstSegmentEnd[]; extern u8 _ovl_Boss_SstSegmentRomStart[]; extern u8 _ovl_Boss_SstSegmentRomEnd[];
extern u8 _ovl_En_NySegmentStart[]; extern u8 _ovl_En_NySegmentEnd[]; extern u8 _ovl_En_NySegmentRomStart[]; extern u8 _ovl_En_NySegmentRomEnd[];
extern u8 _ovl_En_FrSegmentStart[]; extern u8 _ovl_En_FrSegmentEnd[]; extern u8 _ovl_En_FrSegmentRomStart[]; extern u8 _ovl_En_FrSegmentRomEnd[];
extern u8 _ovl_Item_ShieldSegmentStart[]; extern u8 _ovl_Item_ShieldSegmentEnd[]; extern u8 _ovl_Item_ShieldSegmentRomStart[]; extern u8 _ovl_Item_ShieldSegmentRomEnd[];
extern u8 _ovl_Bg_Ice_ShelterSegmentStart[]; extern u8 _ovl_Bg_Ice_ShelterSegmentEnd[]; extern u8 _ovl_Bg_Ice_ShelterSegmentRomStart[]; extern u8 _ovl_Bg_Ice_ShelterSegmentRomEnd[];
extern u8 _ovl_En_Ice_HonoSegmentStart[]; extern u8 _ovl_En_Ice_HonoSegmentEnd[]; extern u8 _ovl_En_Ice_HonoSegmentRomStart[]; extern u8 _ovl_En_Ice_HonoSegmentRomEnd[];
extern u8 _ovl_Item_OcarinaSegmentStart[]; extern u8 _ovl_Item_OcarinaSegmentEnd[]; extern u8 _ovl_Item_OcarinaSegmentRomStart[]; extern u8 _ovl_Item_OcarinaSegmentRomEnd[];
extern u8 _ovl_Magic_DarkSegmentStart[]; extern u8 _ovl_Magic_DarkSegmentEnd[]; extern u8 _ovl_Magic_DarkSegmentRomStart[]; extern u8 _ovl_Magic_DarkSegmentRomEnd[];
extern u8 _ovl_Demo_6KSegmentStart[]; extern u8 _ovl_Demo_6KSegmentEnd[]; extern u8 _ovl_Demo_6KSegmentRomStart[]; extern u8 _ovl_Demo_6KSegmentRomEnd[];
extern u8 _ovl_En_Anubice_TagSegmentStart[]; extern u8 _ovl_En_Anubice_TagSegmentEnd[]; extern u8 _ovl_En_Anubice_TagSegmentRomStart[]; extern u8 _ovl_En_Anubice_TagSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_GateSegmentStart[]; extern u8 _ovl_Bg_Haka_GateSegmentEnd[]; extern u8 _ovl_Bg_Haka_GateSegmentRomStart[]; extern u8 _ovl_Bg_Haka_GateSegmentRomEnd[];
extern u8 _ovl_Bg_Spot15_SakuSegmentStart[]; extern u8 _ovl_Bg_Spot15_SakuSegmentEnd[]; extern u8 _ovl_Bg_Spot15_SakuSegmentRomStart[]; extern u8 _ovl_Bg_Spot15_SakuSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_GoroiwaSegmentStart[]; extern u8 _ovl_Bg_Jya_GoroiwaSegmentEnd[]; extern u8 _ovl_Bg_Jya_GoroiwaSegmentRomStart[]; extern u8 _ovl_Bg_Jya_GoroiwaSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_ZurerukabeSegmentStart[]; extern u8 _ovl_Bg_Jya_ZurerukabeSegmentEnd[]; extern u8 _ovl_Bg_Jya_ZurerukabeSegmentRomStart[]; extern u8 _ovl_Bg_Jya_ZurerukabeSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_CobraSegmentStart[]; extern u8 _ovl_Bg_Jya_CobraSegmentEnd[]; extern u8 _ovl_Bg_Jya_CobraSegmentRomStart[]; extern u8 _ovl_Bg_Jya_CobraSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_KanaamiSegmentStart[]; extern u8 _ovl_Bg_Jya_KanaamiSegmentEnd[]; extern u8 _ovl_Bg_Jya_KanaamiSegmentRomStart[]; extern u8 _ovl_Bg_Jya_KanaamiSegmentRomEnd[];
extern u8 _ovl_FishingSegmentStart[]; extern u8 _ovl_FishingSegmentEnd[]; extern u8 _ovl_FishingSegmentRomStart[]; extern u8 _ovl_FishingSegmentRomEnd[];
extern u8 _ovl_Obj_OshihikiSegmentStart[]; extern u8 _ovl_Obj_OshihikiSegmentEnd[]; extern u8 _ovl_Obj_OshihikiSegmentRomStart[]; extern u8 _ovl_Obj_OshihikiSegmentRomEnd[];
extern u8 _ovl_Bg_Gate_ShutterSegmentStart[]; extern u8 _ovl_Bg_Gate_ShutterSegmentEnd[]; extern u8 _ovl_Bg_Gate_ShutterSegmentRomStart[]; extern u8 _ovl_Bg_Gate_ShutterSegmentRomEnd[];
extern u8 _ovl_Eff_DustSegmentStart[]; extern u8 _ovl_Eff_DustSegmentEnd[]; extern u8 _ovl_Eff_DustSegmentRomStart[]; extern u8 _ovl_Eff_DustSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_FusyaSegmentStart[]; extern u8 _ovl_Bg_Spot01_FusyaSegmentEnd[]; extern u8 _ovl_Bg_Spot01_FusyaSegmentRomStart[]; extern u8 _ovl_Bg_Spot01_FusyaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_IdohashiraSegmentStart[]; extern u8 _ovl_Bg_Spot01_IdohashiraSegmentEnd[]; extern u8 _ovl_Bg_Spot01_IdohashiraSegmentRomStart[]; extern u8 _ovl_Bg_Spot01_IdohashiraSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_IdomizuSegmentStart[]; extern u8 _ovl_Bg_Spot01_IdomizuSegmentEnd[]; extern u8 _ovl_Bg_Spot01_IdomizuSegmentRomStart[]; extern u8 _ovl_Bg_Spot01_IdomizuSegmentRomEnd[];
extern u8 _ovl_Bg_Po_SyokudaiSegmentStart[]; extern u8 _ovl_Bg_Po_SyokudaiSegmentEnd[]; extern u8 _ovl_Bg_Po_SyokudaiSegmentRomStart[]; extern u8 _ovl_Bg_Po_SyokudaiSegmentRomEnd[];
extern u8 _ovl_Bg_Ganon_OtyukaSegmentStart[]; extern u8 _ovl_Bg_Ganon_OtyukaSegmentEnd[]; extern u8 _ovl_Bg_Ganon_OtyukaSegmentRomStart[]; extern u8 _ovl_Bg_Ganon_OtyukaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot15_RrboxSegmentStart[]; extern u8 _ovl_Bg_Spot15_RrboxSegmentEnd[]; extern u8 _ovl_Bg_Spot15_RrboxSegmentRomStart[]; extern u8 _ovl_Bg_Spot15_RrboxSegmentRomEnd[];
extern u8 _ovl_Bg_UmajumpSegmentStart[]; extern u8 _ovl_Bg_UmajumpSegmentEnd[]; extern u8 _ovl_Bg_UmajumpSegmentRomStart[]; extern u8 _ovl_Bg_UmajumpSegmentRomEnd[];
extern u8 _ovl_Arrow_FireSegmentStart[]; extern u8 _ovl_Arrow_FireSegmentEnd[]; extern u8 _ovl_Arrow_FireSegmentRomStart[]; extern u8 _ovl_Arrow_FireSegmentRomEnd[];
extern u8 _ovl_Arrow_IceSegmentStart[]; extern u8 _ovl_Arrow_IceSegmentEnd[]; extern u8 _ovl_Arrow_IceSegmentRomStart[]; extern u8 _ovl_Arrow_IceSegmentRomEnd[];
extern u8 _ovl_Arrow_LightSegmentStart[]; extern u8 _ovl_Arrow_LightSegmentEnd[]; extern u8 _ovl_Arrow_LightSegmentRomStart[]; extern u8 _ovl_Arrow_LightSegmentRomEnd[];
extern u8 _ovl_Item_EtceteraSegmentStart[]; extern u8 _ovl_Item_EtceteraSegmentEnd[]; extern u8 _ovl_Item_EtceteraSegmentRomStart[]; extern u8 _ovl_Item_EtceteraSegmentRomEnd[];
extern u8 _ovl_Obj_KibakoSegmentStart[]; extern u8 _ovl_Obj_KibakoSegmentEnd[]; extern u8 _ovl_Obj_KibakoSegmentRomStart[]; extern u8 _ovl_Obj_KibakoSegmentRomEnd[];
extern u8 _ovl_Obj_TsuboSegmentStart[]; extern u8 _ovl_Obj_TsuboSegmentEnd[]; extern u8 _ovl_Obj_TsuboSegmentRomStart[]; extern u8 _ovl_Obj_TsuboSegmentRomEnd[];
extern u8 _ovl_En_Wonder_ItemSegmentStart[]; extern u8 _ovl_En_Wonder_ItemSegmentEnd[]; extern u8 _ovl_En_Wonder_ItemSegmentRomStart[]; extern u8 _ovl_En_Wonder_ItemSegmentRomEnd[];
extern u8 _ovl_En_IkSegmentStart[]; extern u8 _ovl_En_IkSegmentEnd[]; extern u8 _ovl_En_IkSegmentRomStart[]; extern u8 _ovl_En_IkSegmentRomEnd[];
extern u8 _ovl_Demo_IkSegmentStart[]; extern u8 _ovl_Demo_IkSegmentEnd[]; extern u8 _ovl_Demo_IkSegmentRomStart[]; extern u8 _ovl_Demo_IkSegmentRomEnd[];
extern u8 _ovl_En_SkjSegmentStart[]; extern u8 _ovl_En_SkjSegmentEnd[]; extern u8 _ovl_En_SkjSegmentRomStart[]; extern u8 _ovl_En_SkjSegmentRomEnd[];
extern u8 _ovl_En_SkjneedleSegmentStart[]; extern u8 _ovl_En_SkjneedleSegmentEnd[]; extern u8 _ovl_En_SkjneedleSegmentRomStart[]; extern u8 _ovl_En_SkjneedleSegmentRomEnd[];
extern u8 _ovl_En_G_SwitchSegmentStart[]; extern u8 _ovl_En_G_SwitchSegmentEnd[]; extern u8 _ovl_En_G_SwitchSegmentRomStart[]; extern u8 _ovl_En_G_SwitchSegmentRomEnd[];
extern u8 _ovl_Demo_ExtSegmentStart[]; extern u8 _ovl_Demo_ExtSegmentEnd[]; extern u8 _ovl_Demo_ExtSegmentRomStart[]; extern u8 _ovl_Demo_ExtSegmentRomEnd[];
extern u8 _ovl_Demo_ShdSegmentStart[]; extern u8 _ovl_Demo_ShdSegmentEnd[]; extern u8 _ovl_Demo_ShdSegmentRomStart[]; extern u8 _ovl_Demo_ShdSegmentRomEnd[];
extern u8 _ovl_En_DnsSegmentStart[]; extern u8 _ovl_En_DnsSegmentEnd[]; extern u8 _ovl_En_DnsSegmentRomStart[]; extern u8 _ovl_En_DnsSegmentRomEnd[];
extern u8 _ovl_Elf_MsgSegmentStart[]; extern u8 _ovl_Elf_MsgSegmentEnd[]; extern u8 _ovl_Elf_MsgSegmentRomStart[]; extern u8 _ovl_Elf_MsgSegmentRomEnd[];
extern u8 _ovl_En_HonotrapSegmentStart[]; extern u8 _ovl_En_HonotrapSegmentEnd[]; extern u8 _ovl_En_HonotrapSegmentRomStart[]; extern u8 _ovl_En_HonotrapSegmentRomEnd[];
extern u8 _ovl_En_Tubo_TrapSegmentStart[]; extern u8 _ovl_En_Tubo_TrapSegmentEnd[]; extern u8 _ovl_En_Tubo_TrapSegmentRomStart[]; extern u8 _ovl_En_Tubo_TrapSegmentRomEnd[];
extern u8 _ovl_Obj_Ice_PolySegmentStart[]; extern u8 _ovl_Obj_Ice_PolySegmentEnd[]; extern u8 _ovl_Obj_Ice_PolySegmentRomStart[]; extern u8 _ovl_Obj_Ice_PolySegmentRomEnd[];
extern u8 _ovl_Bg_Spot03_TakiSegmentStart[]; extern u8 _ovl_Bg_Spot03_TakiSegmentEnd[]; extern u8 _ovl_Bg_Spot03_TakiSegmentRomStart[]; extern u8 _ovl_Bg_Spot03_TakiSegmentRomEnd[];
extern u8 _ovl_Bg_Spot07_TakiSegmentStart[]; extern u8 _ovl_Bg_Spot07_TakiSegmentEnd[]; extern u8 _ovl_Bg_Spot07_TakiSegmentRomStart[]; extern u8 _ovl_Bg_Spot07_TakiSegmentRomEnd[];
extern u8 _ovl_En_FzSegmentStart[]; extern u8 _ovl_En_FzSegmentEnd[]; extern u8 _ovl_En_FzSegmentRomStart[]; extern u8 _ovl_En_FzSegmentRomEnd[];
extern u8 _ovl_En_Po_RelaySegmentStart[]; extern u8 _ovl_En_Po_RelaySegmentEnd[]; extern u8 _ovl_En_Po_RelaySegmentRomStart[]; extern u8 _ovl_En_Po_RelaySegmentRomEnd[];
extern u8 _ovl_Bg_Relay_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Relay_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Relay_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Relay_ObjectsSegmentRomEnd[];
extern u8 _ovl_En_Diving_GameSegmentStart[]; extern u8 _ovl_En_Diving_GameSegmentEnd[]; extern u8 _ovl_En_Diving_GameSegmentRomStart[]; extern u8 _ovl_En_Diving_GameSegmentRomEnd[];
extern u8 _ovl_En_KusaSegmentStart[]; extern u8 _ovl_En_KusaSegmentEnd[]; extern u8 _ovl_En_KusaSegmentRomStart[]; extern u8 _ovl_En_KusaSegmentRomEnd[];
extern u8 _ovl_Obj_BeanSegmentStart[]; extern u8 _ovl_Obj_BeanSegmentEnd[]; extern u8 _ovl_Obj_BeanSegmentRomStart[]; extern u8 _ovl_Obj_BeanSegmentRomEnd[];
extern u8 _ovl_Obj_BombiwaSegmentStart[]; extern u8 _ovl_Obj_BombiwaSegmentEnd[]; extern u8 _ovl_Obj_BombiwaSegmentRomStart[]; extern u8 _ovl_Obj_BombiwaSegmentRomEnd[];
extern u8 _ovl_Obj_SwitchSegmentStart[]; extern u8 _ovl_Obj_SwitchSegmentEnd[]; extern u8 _ovl_Obj_SwitchSegmentRomStart[]; extern u8 _ovl_Obj_SwitchSegmentRomEnd[];
extern u8 _ovl_Obj_ElevatorSegmentStart[]; extern u8 _ovl_Obj_ElevatorSegmentEnd[]; extern u8 _ovl_Obj_ElevatorSegmentRomStart[]; extern u8 _ovl_Obj_ElevatorSegmentRomEnd[];
extern u8 _ovl_Obj_LiftSegmentStart[]; extern u8 _ovl_Obj_LiftSegmentEnd[]; extern u8 _ovl_Obj_LiftSegmentRomStart[]; extern u8 _ovl_Obj_LiftSegmentRomEnd[];
extern u8 _ovl_Obj_HsblockSegmentStart[]; extern u8 _ovl_Obj_HsblockSegmentEnd[]; extern u8 _ovl_Obj_HsblockSegmentRomStart[]; extern u8 _ovl_Obj_HsblockSegmentRomEnd[];
extern u8 _ovl_En_Okarina_TagSegmentStart[]; extern u8 _ovl_En_Okarina_TagSegmentEnd[]; extern u8 _ovl_En_Okarina_TagSegmentRomStart[]; extern u8 _ovl_En_Okarina_TagSegmentRomEnd[];
extern u8 _ovl_En_Yabusame_MarkSegmentStart[]; extern u8 _ovl_En_Yabusame_MarkSegmentEnd[]; extern u8 _ovl_En_Yabusame_MarkSegmentRomStart[]; extern u8 _ovl_En_Yabusame_MarkSegmentRomEnd[];
extern u8 _ovl_En_GoroiwaSegmentStart[]; extern u8 _ovl_En_GoroiwaSegmentEnd[]; extern u8 _ovl_En_GoroiwaSegmentRomStart[]; extern u8 _ovl_En_GoroiwaSegmentRomEnd[];
extern u8 _ovl_En_Ex_RuppySegmentStart[]; extern u8 _ovl_En_Ex_RuppySegmentEnd[]; extern u8 _ovl_En_Ex_RuppySegmentRomStart[]; extern u8 _ovl_En_Ex_RuppySegmentRomEnd[];
extern u8 _ovl_En_ToryoSegmentStart[]; extern u8 _ovl_En_ToryoSegmentEnd[]; extern u8 _ovl_En_ToryoSegmentRomStart[]; extern u8 _ovl_En_ToryoSegmentRomEnd[];
extern u8 _ovl_En_DaikuSegmentStart[]; extern u8 _ovl_En_DaikuSegmentEnd[]; extern u8 _ovl_En_DaikuSegmentRomStart[]; extern u8 _ovl_En_DaikuSegmentRomEnd[];
extern u8 _ovl_En_NwcSegmentStart[]; extern u8 _ovl_En_NwcSegmentEnd[]; extern u8 _ovl_En_NwcSegmentRomStart[]; extern u8 _ovl_En_NwcSegmentRomEnd[];
extern u8 _ovl_En_BlkobjSegmentStart[]; extern u8 _ovl_En_BlkobjSegmentEnd[]; extern u8 _ovl_En_BlkobjSegmentRomStart[]; extern u8 _ovl_En_BlkobjSegmentRomEnd[];
extern u8 _ovl_Item_InboxSegmentStart[]; extern u8 _ovl_Item_InboxSegmentEnd[]; extern u8 _ovl_Item_InboxSegmentRomStart[]; extern u8 _ovl_Item_InboxSegmentRomEnd[];
extern u8 _ovl_En_Ge1SegmentStart[]; extern u8 _ovl_En_Ge1SegmentEnd[]; extern u8 _ovl_En_Ge1SegmentRomStart[]; extern u8 _ovl_En_Ge1SegmentRomEnd[];
extern u8 _ovl_Obj_BlockstopSegmentStart[]; extern u8 _ovl_Obj_BlockstopSegmentEnd[]; extern u8 _ovl_Obj_BlockstopSegmentRomStart[]; extern u8 _ovl_Obj_BlockstopSegmentRomEnd[];
extern u8 _ovl_En_SdaSegmentStart[]; extern u8 _ovl_En_SdaSegmentEnd[]; extern u8 _ovl_En_SdaSegmentRomStart[]; extern u8 _ovl_En_SdaSegmentRomEnd[];
extern u8 _ovl_En_Clear_TagSegmentStart[]; extern u8 _ovl_En_Clear_TagSegmentEnd[]; extern u8 _ovl_En_Clear_TagSegmentRomStart[]; extern u8 _ovl_En_Clear_TagSegmentRomEnd[];
extern u8 _ovl_En_Niw_LadySegmentStart[]; extern u8 _ovl_En_Niw_LadySegmentEnd[]; extern u8 _ovl_En_Niw_LadySegmentRomStart[]; extern u8 _ovl_En_Niw_LadySegmentRomEnd[];
extern u8 _ovl_En_GmSegmentStart[]; extern u8 _ovl_En_GmSegmentEnd[]; extern u8 _ovl_En_GmSegmentRomStart[]; extern u8 _ovl_En_GmSegmentRomEnd[];
extern u8 _ovl_En_MsSegmentStart[]; extern u8 _ovl_En_MsSegmentEnd[]; extern u8 _ovl_En_MsSegmentRomStart[]; extern u8 _ovl_En_MsSegmentRomEnd[];
extern u8 _ovl_En_HsSegmentStart[]; extern u8 _ovl_En_HsSegmentEnd[]; extern u8 _ovl_En_HsSegmentRomStart[]; extern u8 _ovl_En_HsSegmentRomEnd[];
extern u8 _ovl_Bg_IngateSegmentStart[]; extern u8 _ovl_Bg_IngateSegmentEnd[]; extern u8 _ovl_Bg_IngateSegmentRomStart[]; extern u8 _ovl_Bg_IngateSegmentRomEnd[];
extern u8 _ovl_En_KanbanSegmentStart[]; extern u8 _ovl_En_KanbanSegmentEnd[]; extern u8 _ovl_En_KanbanSegmentRomStart[]; extern u8 _ovl_En_KanbanSegmentRomEnd[];
extern u8 _ovl_En_Heishi3SegmentStart[]; extern u8 _ovl_En_Heishi3SegmentEnd[]; extern u8 _ovl_En_Heishi3SegmentRomStart[]; extern u8 _ovl_En_Heishi3SegmentRomEnd[];
extern u8 _ovl_En_Syateki_NiwSegmentStart[]; extern u8 _ovl_En_Syateki_NiwSegmentEnd[]; extern u8 _ovl_En_Syateki_NiwSegmentRomStart[]; extern u8 _ovl_En_Syateki_NiwSegmentRomEnd[];
extern u8 _ovl_En_Attack_NiwSegmentStart[]; extern u8 _ovl_En_Attack_NiwSegmentEnd[]; extern u8 _ovl_En_Attack_NiwSegmentRomStart[]; extern u8 _ovl_En_Attack_NiwSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_IdosokoSegmentStart[]; extern u8 _ovl_Bg_Spot01_IdosokoSegmentEnd[]; extern u8 _ovl_Bg_Spot01_IdosokoSegmentRomStart[]; extern u8 _ovl_Bg_Spot01_IdosokoSegmentRomEnd[];
extern u8 _ovl_En_SaSegmentStart[]; extern u8 _ovl_En_SaSegmentEnd[]; extern u8 _ovl_En_SaSegmentRomStart[]; extern u8 _ovl_En_SaSegmentRomEnd[];
extern u8 _ovl_En_Wonder_TalkSegmentStart[]; extern u8 _ovl_En_Wonder_TalkSegmentEnd[]; extern u8 _ovl_En_Wonder_TalkSegmentRomStart[]; extern u8 _ovl_En_Wonder_TalkSegmentRomEnd[];
extern u8 _ovl_Bg_Gjyo_BridgeSegmentStart[]; extern u8 _ovl_Bg_Gjyo_BridgeSegmentEnd[]; extern u8 _ovl_Bg_Gjyo_BridgeSegmentRomStart[]; extern u8 _ovl_Bg_Gjyo_BridgeSegmentRomEnd[];
extern u8 _ovl_En_DsSegmentStart[]; extern u8 _ovl_En_DsSegmentEnd[]; extern u8 _ovl_En_DsSegmentRomStart[]; extern u8 _ovl_En_DsSegmentRomEnd[];
extern u8 _ovl_En_MkSegmentStart[]; extern u8 _ovl_En_MkSegmentEnd[]; extern u8 _ovl_En_MkSegmentRomStart[]; extern u8 _ovl_En_MkSegmentRomEnd[];
extern u8 _ovl_En_Bom_Bowl_ManSegmentStart[]; extern u8 _ovl_En_Bom_Bowl_ManSegmentEnd[]; extern u8 _ovl_En_Bom_Bowl_ManSegmentRomStart[]; extern u8 _ovl_En_Bom_Bowl_ManSegmentRomEnd[];
extern u8 _ovl_En_Bom_Bowl_PitSegmentStart[]; extern u8 _ovl_En_Bom_Bowl_PitSegmentEnd[]; extern u8 _ovl_En_Bom_Bowl_PitSegmentRomStart[]; extern u8 _ovl_En_Bom_Bowl_PitSegmentRomEnd[];
extern u8 _ovl_En_OwlSegmentStart[]; extern u8 _ovl_En_OwlSegmentEnd[]; extern u8 _ovl_En_OwlSegmentRomStart[]; extern u8 _ovl_En_OwlSegmentRomEnd[];
extern u8 _ovl_En_IshiSegmentStart[]; extern u8 _ovl_En_IshiSegmentEnd[]; extern u8 _ovl_En_IshiSegmentRomStart[]; extern u8 _ovl_En_IshiSegmentRomEnd[];
extern u8 _ovl_Obj_HanaSegmentStart[]; extern u8 _ovl_Obj_HanaSegmentEnd[]; extern u8 _ovl_Obj_HanaSegmentRomStart[]; extern u8 _ovl_Obj_HanaSegmentRomEnd[];
extern u8 _ovl_Obj_LightswitchSegmentStart[]; extern u8 _ovl_Obj_LightswitchSegmentEnd[]; extern u8 _ovl_Obj_LightswitchSegmentRomStart[]; extern u8 _ovl_Obj_LightswitchSegmentRomEnd[];
extern u8 _ovl_Obj_Mure2SegmentStart[]; extern u8 _ovl_Obj_Mure2SegmentEnd[]; extern u8 _ovl_Obj_Mure2SegmentRomStart[]; extern u8 _ovl_Obj_Mure2SegmentRomEnd[];
extern u8 _ovl_En_GoSegmentStart[]; extern u8 _ovl_En_GoSegmentEnd[]; extern u8 _ovl_En_GoSegmentRomStart[]; extern u8 _ovl_En_GoSegmentRomEnd[];
extern u8 _ovl_En_FuSegmentStart[]; extern u8 _ovl_En_FuSegmentEnd[]; extern u8 _ovl_En_FuSegmentRomStart[]; extern u8 _ovl_En_FuSegmentRomEnd[];
extern u8 _ovl_En_ChangerSegmentStart[]; extern u8 _ovl_En_ChangerSegmentEnd[]; extern u8 _ovl_En_ChangerSegmentRomStart[]; extern u8 _ovl_En_ChangerSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_MegamiSegmentStart[]; extern u8 _ovl_Bg_Jya_MegamiSegmentEnd[]; extern u8 _ovl_Bg_Jya_MegamiSegmentRomStart[]; extern u8 _ovl_Bg_Jya_MegamiSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_LiftSegmentStart[]; extern u8 _ovl_Bg_Jya_LiftSegmentEnd[]; extern u8 _ovl_Bg_Jya_LiftSegmentRomStart[]; extern u8 _ovl_Bg_Jya_LiftSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_BigmirrorSegmentStart[]; extern u8 _ovl_Bg_Jya_BigmirrorSegmentEnd[]; extern u8 _ovl_Bg_Jya_BigmirrorSegmentRomStart[]; extern u8 _ovl_Bg_Jya_BigmirrorSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_BombchuiwaSegmentStart[]; extern u8 _ovl_Bg_Jya_BombchuiwaSegmentEnd[]; extern u8 _ovl_Bg_Jya_BombchuiwaSegmentRomStart[]; extern u8 _ovl_Bg_Jya_BombchuiwaSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_AmishutterSegmentStart[]; extern u8 _ovl_Bg_Jya_AmishutterSegmentEnd[]; extern u8 _ovl_Bg_Jya_AmishutterSegmentRomStart[]; extern u8 _ovl_Bg_Jya_AmishutterSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_BombiwaSegmentStart[]; extern u8 _ovl_Bg_Jya_BombiwaSegmentEnd[]; extern u8 _ovl_Bg_Jya_BombiwaSegmentRomStart[]; extern u8 _ovl_Bg_Jya_BombiwaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot18_BasketSegmentStart[]; extern u8 _ovl_Bg_Spot18_BasketSegmentEnd[]; extern u8 _ovl_Bg_Spot18_BasketSegmentRomStart[]; extern u8 _ovl_Bg_Spot18_BasketSegmentRomEnd[];
extern u8 _ovl_En_Ganon_OrganSegmentStart[]; extern u8 _ovl_En_Ganon_OrganSegmentEnd[]; extern u8 _ovl_En_Ganon_OrganSegmentRomStart[]; extern u8 _ovl_En_Ganon_OrganSegmentRomEnd[];
extern u8 _ovl_En_SiofukiSegmentStart[]; extern u8 _ovl_En_SiofukiSegmentEnd[]; extern u8 _ovl_En_SiofukiSegmentRomStart[]; extern u8 _ovl_En_SiofukiSegmentRomEnd[];
extern u8 _ovl_En_StreamSegmentStart[]; extern u8 _ovl_En_StreamSegmentEnd[]; extern u8 _ovl_En_StreamSegmentRomStart[]; extern u8 _ovl_En_StreamSegmentRomEnd[];
extern u8 _ovl_En_MmSegmentStart[]; extern u8 _ovl_En_MmSegmentEnd[]; extern u8 _ovl_En_MmSegmentRomStart[]; extern u8 _ovl_En_MmSegmentRomEnd[];
extern u8 _ovl_En_KoSegmentStart[]; extern u8 _ovl_En_KoSegmentEnd[]; extern u8 _ovl_En_KoSegmentRomStart[]; extern u8 _ovl_En_KoSegmentRomEnd[];
extern u8 _ovl_En_KzSegmentStart[]; extern u8 _ovl_En_KzSegmentEnd[]; extern u8 _ovl_En_KzSegmentRomStart[]; extern u8 _ovl_En_KzSegmentRomEnd[];
extern u8 _ovl_En_Weather_TagSegmentStart[]; extern u8 _ovl_En_Weather_TagSegmentEnd[]; extern u8 _ovl_En_Weather_TagSegmentRomStart[]; extern u8 _ovl_En_Weather_TagSegmentRomEnd[];
extern u8 _ovl_Bg_Sst_FloorSegmentStart[]; extern u8 _ovl_Bg_Sst_FloorSegmentEnd[]; extern u8 _ovl_Bg_Sst_FloorSegmentRomStart[]; extern u8 _ovl_Bg_Sst_FloorSegmentRomEnd[];
extern u8 _ovl_En_AniSegmentStart[]; extern u8 _ovl_En_AniSegmentEnd[]; extern u8 _ovl_En_AniSegmentRomStart[]; extern u8 _ovl_En_AniSegmentRomEnd[];
extern u8 _ovl_En_Ex_ItemSegmentStart[]; extern u8 _ovl_En_Ex_ItemSegmentEnd[]; extern u8 _ovl_En_Ex_ItemSegmentRomStart[]; extern u8 _ovl_En_Ex_ItemSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_IronobjSegmentStart[]; extern u8 _ovl_Bg_Jya_IronobjSegmentEnd[]; extern u8 _ovl_Bg_Jya_IronobjSegmentRomStart[]; extern u8 _ovl_Bg_Jya_IronobjSegmentRomEnd[];
extern u8 _ovl_En_JsSegmentStart[]; extern u8 _ovl_En_JsSegmentEnd[]; extern u8 _ovl_En_JsSegmentRomStart[]; extern u8 _ovl_En_JsSegmentRomEnd[];
extern u8 _ovl_En_JsjutanSegmentStart[]; extern u8 _ovl_En_JsjutanSegmentEnd[]; extern u8 _ovl_En_JsjutanSegmentRomStart[]; extern u8 _ovl_En_JsjutanSegmentRomEnd[];
extern u8 _ovl_En_CsSegmentStart[]; extern u8 _ovl_En_CsSegmentEnd[]; extern u8 _ovl_En_CsSegmentRomStart[]; extern u8 _ovl_En_CsSegmentRomEnd[];
extern u8 _ovl_En_MdSegmentStart[]; extern u8 _ovl_En_MdSegmentEnd[]; extern u8 _ovl_En_MdSegmentRomStart[]; extern u8 _ovl_En_MdSegmentRomEnd[];
extern u8 _ovl_En_HySegmentStart[]; extern u8 _ovl_En_HySegmentEnd[]; extern u8 _ovl_En_HySegmentRomStart[]; extern u8 _ovl_En_HySegmentRomEnd[];
extern u8 _ovl_En_Ganon_MantSegmentStart[]; extern u8 _ovl_En_Ganon_MantSegmentEnd[]; extern u8 _ovl_En_Ganon_MantSegmentRomStart[]; extern u8 _ovl_En_Ganon_MantSegmentRomEnd[];
extern u8 _ovl_En_Okarina_EffectSegmentStart[]; extern u8 _ovl_En_Okarina_EffectSegmentEnd[]; extern u8 _ovl_En_Okarina_EffectSegmentRomStart[]; extern u8 _ovl_En_Okarina_EffectSegmentRomEnd[];
extern u8 _ovl_En_MagSegmentStart[]; extern u8 _ovl_En_MagSegmentEnd[]; extern u8 _ovl_En_MagSegmentRomStart[]; extern u8 _ovl_En_MagSegmentRomEnd[];
extern u8 _ovl_Door_GerudoSegmentStart[]; extern u8 _ovl_Door_GerudoSegmentEnd[]; extern u8 _ovl_Door_GerudoSegmentRomStart[]; extern u8 _ovl_Door_GerudoSegmentRomEnd[];
extern u8 _ovl_Elf_Msg2SegmentStart[]; extern u8 _ovl_Elf_Msg2SegmentEnd[]; extern u8 _ovl_Elf_Msg2SegmentRomStart[]; extern u8 _ovl_Elf_Msg2SegmentRomEnd[];
extern u8 _ovl_Demo_GtSegmentStart[]; extern u8 _ovl_Demo_GtSegmentEnd[]; extern u8 _ovl_Demo_GtSegmentRomStart[]; extern u8 _ovl_Demo_GtSegmentRomEnd[];
extern u8 _ovl_En_Po_FieldSegmentStart[]; extern u8 _ovl_En_Po_FieldSegmentEnd[]; extern u8 _ovl_En_Po_FieldSegmentRomStart[]; extern u8 _ovl_En_Po_FieldSegmentRomEnd[];
extern u8 _ovl_Efc_ErupcSegmentStart[]; extern u8 _ovl_Efc_ErupcSegmentEnd[]; extern u8 _ovl_Efc_ErupcSegmentRomStart[]; extern u8 _ovl_Efc_ErupcSegmentRomEnd[];
extern u8 _ovl_Bg_ZgSegmentStart[]; extern u8 _ovl_Bg_ZgSegmentEnd[]; extern u8 _ovl_Bg_ZgSegmentRomStart[]; extern u8 _ovl_Bg_ZgSegmentRomEnd[];
extern u8 _ovl_En_Heishi4SegmentStart[]; extern u8 _ovl_En_Heishi4SegmentEnd[]; extern u8 _ovl_En_Heishi4SegmentRomStart[]; extern u8 _ovl_En_Heishi4SegmentRomEnd[];
extern u8 _ovl_En_Zl3SegmentStart[]; extern u8 _ovl_En_Zl3SegmentEnd[]; extern u8 _ovl_En_Zl3SegmentRomStart[]; extern u8 _ovl_En_Zl3SegmentRomEnd[];
extern u8 _ovl_Boss_Ganon2SegmentStart[]; extern u8 _ovl_Boss_Ganon2SegmentEnd[]; extern u8 _ovl_Boss_Ganon2SegmentRomStart[]; extern u8 _ovl_Boss_Ganon2SegmentRomEnd[];
extern u8 _ovl_En_KakasiSegmentStart[]; extern u8 _ovl_En_KakasiSegmentEnd[]; extern u8 _ovl_En_KakasiSegmentRomStart[]; extern u8 _ovl_En_KakasiSegmentRomEnd[];
extern u8 _ovl_En_Takara_ManSegmentStart[]; extern u8 _ovl_En_Takara_ManSegmentEnd[]; extern u8 _ovl_En_Takara_ManSegmentRomStart[]; extern u8 _ovl_En_Takara_ManSegmentRomEnd[];
extern u8 _ovl_Obj_MakeoshihikiSegmentStart[]; extern u8 _ovl_Obj_MakeoshihikiSegmentEnd[]; extern u8 _ovl_Obj_MakeoshihikiSegmentRomStart[]; extern u8 _ovl_Obj_MakeoshihikiSegmentRomEnd[];
extern u8 _ovl_Oceff_SpotSegmentStart[]; extern u8 _ovl_Oceff_SpotSegmentEnd[]; extern u8 _ovl_Oceff_SpotSegmentRomStart[]; extern u8 _ovl_Oceff_SpotSegmentRomEnd[];
extern u8 _ovl_End_TitleSegmentStart[]; extern u8 _ovl_End_TitleSegmentEnd[]; extern u8 _ovl_End_TitleSegmentRomStart[]; extern u8 _ovl_End_TitleSegmentRomEnd[];
extern u8 _ovl_En_TorchSegmentStart[]; extern u8 _ovl_En_TorchSegmentEnd[]; extern u8 _ovl_En_TorchSegmentRomStart[]; extern u8 _ovl_En_TorchSegmentRomEnd[];
extern u8 _ovl_Demo_EcSegmentStart[]; extern u8 _ovl_Demo_EcSegmentEnd[]; extern u8 _ovl_Demo_EcSegmentRomStart[]; extern u8 _ovl_Demo_EcSegmentRomEnd[];
extern u8 _ovl_Shot_SunSegmentStart[]; extern u8 _ovl_Shot_SunSegmentEnd[]; extern u8 _ovl_Shot_SunSegmentRomStart[]; extern u8 _ovl_Shot_SunSegmentRomEnd[];
extern u8 _ovl_En_Dy_ExtraSegmentStart[]; extern u8 _ovl_En_Dy_ExtraSegmentEnd[]; extern u8 _ovl_En_Dy_ExtraSegmentRomStart[]; extern u8 _ovl_En_Dy_ExtraSegmentRomEnd[];
extern u8 _ovl_En_Wonder_Talk2SegmentStart[]; extern u8 _ovl_En_Wonder_Talk2SegmentEnd[]; extern u8 _ovl_En_Wonder_Talk2SegmentRomStart[]; extern u8 _ovl_En_Wonder_Talk2SegmentRomEnd[];
extern u8 _ovl_En_Ge2SegmentStart[]; extern u8 _ovl_En_Ge2SegmentEnd[]; extern u8 _ovl_En_Ge2SegmentRomStart[]; extern u8 _ovl_En_Ge2SegmentRomEnd[];
extern u8 _ovl_Obj_RoomtimerSegmentStart[]; extern u8 _ovl_Obj_RoomtimerSegmentEnd[]; extern u8 _ovl_Obj_RoomtimerSegmentRomStart[]; extern u8 _ovl_Obj_RoomtimerSegmentRomEnd[];
extern u8 _ovl_En_SshSegmentStart[]; extern u8 _ovl_En_SshSegmentEnd[]; extern u8 _ovl_En_SshSegmentRomStart[]; extern u8 _ovl_En_SshSegmentRomEnd[];
extern u8 _ovl_En_SthSegmentStart[]; extern u8 _ovl_En_SthSegmentEnd[]; extern u8 _ovl_En_SthSegmentRomStart[]; extern u8 _ovl_En_SthSegmentRomEnd[];
extern u8 _ovl_Oceff_WipeSegmentStart[]; extern u8 _ovl_Oceff_WipeSegmentEnd[]; extern u8 _ovl_Oceff_WipeSegmentRomStart[]; extern u8 _ovl_Oceff_WipeSegmentRomEnd[];
extern u8 _ovl_Oceff_StormSegmentStart[]; extern u8 _ovl_Oceff_StormSegmentEnd[]; extern u8 _ovl_Oceff_StormSegmentRomStart[]; extern u8 _ovl_Oceff_StormSegmentRomEnd[];
extern u8 _ovl_En_WeiyerSegmentStart[]; extern u8 _ovl_En_WeiyerSegmentEnd[]; extern u8 _ovl_En_WeiyerSegmentRomStart[]; extern u8 _ovl_En_WeiyerSegmentRomEnd[];
extern u8 _ovl_Bg_Spot05_SokoSegmentStart[]; extern u8 _ovl_Bg_Spot05_SokoSegmentEnd[]; extern u8 _ovl_Bg_Spot05_SokoSegmentRomStart[]; extern u8 _ovl_Bg_Spot05_SokoSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_1fliftSegmentStart[]; extern u8 _ovl_Bg_Jya_1fliftSegmentEnd[]; extern u8 _ovl_Bg_Jya_1fliftSegmentRomStart[]; extern u8 _ovl_Bg_Jya_1fliftSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_HahenironSegmentStart[]; extern u8 _ovl_Bg_Jya_HahenironSegmentEnd[]; extern u8 _ovl_Bg_Jya_HahenironSegmentRomStart[]; extern u8 _ovl_Bg_Jya_HahenironSegmentRomEnd[];
extern u8 _ovl_Bg_Spot12_GateSegmentStart[]; extern u8 _ovl_Bg_Spot12_GateSegmentEnd[]; extern u8 _ovl_Bg_Spot12_GateSegmentRomStart[]; extern u8 _ovl_Bg_Spot12_GateSegmentRomEnd[];
extern u8 _ovl_Bg_Spot12_SakuSegmentStart[]; extern u8 _ovl_Bg_Spot12_SakuSegmentEnd[]; extern u8 _ovl_Bg_Spot12_SakuSegmentRomStart[]; extern u8 _ovl_Bg_Spot12_SakuSegmentRomEnd[];
extern u8 _ovl_En_HintnutsSegmentStart[]; extern u8 _ovl_En_HintnutsSegmentEnd[]; extern u8 _ovl_En_HintnutsSegmentRomStart[]; extern u8 _ovl_En_HintnutsSegmentRomEnd[];
extern u8 _ovl_En_NutsballSegmentStart[]; extern u8 _ovl_En_NutsballSegmentEnd[]; extern u8 _ovl_En_NutsballSegmentRomStart[]; extern u8 _ovl_En_NutsballSegmentRomEnd[];
extern u8 _ovl_Bg_Spot00_BreakSegmentStart[]; extern u8 _ovl_Bg_Spot00_BreakSegmentEnd[]; extern u8 _ovl_Bg_Spot00_BreakSegmentRomStart[]; extern u8 _ovl_Bg_Spot00_BreakSegmentRomEnd[];
extern u8 _ovl_En_ShopnutsSegmentStart[]; extern u8 _ovl_En_ShopnutsSegmentEnd[]; extern u8 _ovl_En_ShopnutsSegmentRomStart[]; extern u8 _ovl_En_ShopnutsSegmentRomEnd[];
extern u8 _ovl_En_ItSegmentStart[]; extern u8 _ovl_En_ItSegmentEnd[]; extern u8 _ovl_En_ItSegmentRomStart[]; extern u8 _ovl_En_ItSegmentRomEnd[];
extern u8 _ovl_En_GeldBSegmentStart[]; extern u8 _ovl_En_GeldBSegmentEnd[]; extern u8 _ovl_En_GeldBSegmentRomStart[]; extern u8 _ovl_En_GeldBSegmentRomEnd[];
extern u8 _ovl_Oceff_Wipe2SegmentStart[]; extern u8 _ovl_Oceff_Wipe2SegmentEnd[]; extern u8 _ovl_Oceff_Wipe2SegmentRomStart[]; extern u8 _ovl_Oceff_Wipe2SegmentRomEnd[];
extern u8 _ovl_Oceff_Wipe3SegmentStart[]; extern u8 _ovl_Oceff_Wipe3SegmentEnd[]; extern u8 _ovl_Oceff_Wipe3SegmentRomStart[]; extern u8 _ovl_Oceff_Wipe3SegmentRomEnd[];
extern u8 _ovl_En_Niw_GirlSegmentStart[]; extern u8 _ovl_En_Niw_GirlSegmentEnd[]; extern u8 _ovl_En_Niw_GirlSegmentRomStart[]; extern u8 _ovl_En_Niw_GirlSegmentRomEnd[];
extern u8 _ovl_En_DogSegmentStart[]; extern u8 _ovl_En_DogSegmentEnd[]; extern u8 _ovl_En_DogSegmentRomStart[]; extern u8 _ovl_En_DogSegmentRomEnd[];
extern u8 _ovl_En_SiSegmentStart[]; extern u8 _ovl_En_SiSegmentEnd[]; extern u8 _ovl_En_SiSegmentRomStart[]; extern u8 _ovl_En_SiSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_Objects2SegmentStart[]; extern u8 _ovl_Bg_Spot01_Objects2SegmentEnd[]; extern u8 _ovl_Bg_Spot01_Objects2SegmentRomStart[]; extern u8 _ovl_Bg_Spot01_Objects2SegmentRomEnd[];
extern u8 _ovl_Obj_CombSegmentStart[]; extern u8 _ovl_Obj_CombSegmentEnd[]; extern u8 _ovl_Obj_CombSegmentRomStart[]; extern u8 _ovl_Obj_CombSegmentRomEnd[];
extern u8 _ovl_Bg_Spot11_BakudankabeSegmentStart[]; extern u8 _ovl_Bg_Spot11_BakudankabeSegmentEnd[]; extern u8 _ovl_Bg_Spot11_BakudankabeSegmentRomStart[]; extern u8 _ovl_Bg_Spot11_BakudankabeSegmentRomEnd[];
extern u8 _ovl_Obj_Kibako2SegmentStart[]; extern u8 _ovl_Obj_Kibako2SegmentEnd[]; extern u8 _ovl_Obj_Kibako2SegmentRomStart[]; extern u8 _ovl_Obj_Kibako2SegmentRomEnd[];
extern u8 _ovl_En_Dnt_DemoSegmentStart[]; extern u8 _ovl_En_Dnt_DemoSegmentEnd[]; extern u8 _ovl_En_Dnt_DemoSegmentRomStart[]; extern u8 _ovl_En_Dnt_DemoSegmentRomEnd[];
extern u8 _ovl_En_Dnt_JijiSegmentStart[]; extern u8 _ovl_En_Dnt_JijiSegmentEnd[]; extern u8 _ovl_En_Dnt_JijiSegmentRomStart[]; extern u8 _ovl_En_Dnt_JijiSegmentRomEnd[];
extern u8 _ovl_En_Dnt_NomalSegmentStart[]; extern u8 _ovl_En_Dnt_NomalSegmentEnd[]; extern u8 _ovl_En_Dnt_NomalSegmentRomStart[]; extern u8 _ovl_En_Dnt_NomalSegmentRomEnd[];
extern u8 _ovl_En_GuestSegmentStart[]; extern u8 _ovl_En_GuestSegmentEnd[]; extern u8 _ovl_En_GuestSegmentRomStart[]; extern u8 _ovl_En_GuestSegmentRomEnd[];
extern u8 _ovl_Bg_Bom_GuardSegmentStart[]; extern u8 _ovl_Bg_Bom_GuardSegmentEnd[]; extern u8 _ovl_Bg_Bom_GuardSegmentRomStart[]; extern u8 _ovl_Bg_Bom_GuardSegmentRomEnd[];
extern u8 _ovl_En_Hs2SegmentStart[]; extern u8 _ovl_En_Hs2SegmentEnd[]; extern u8 _ovl_En_Hs2SegmentRomStart[]; extern u8 _ovl_En_Hs2SegmentRomEnd[];
extern u8 _ovl_Demo_KekkaiSegmentStart[]; extern u8 _ovl_Demo_KekkaiSegmentEnd[]; extern u8 _ovl_Demo_KekkaiSegmentRomStart[]; extern u8 _ovl_Demo_KekkaiSegmentRomEnd[];
extern u8 _ovl_Bg_Spot08_BakudankabeSegmentStart[]; extern u8 _ovl_Bg_Spot08_BakudankabeSegmentEnd[]; extern u8 _ovl_Bg_Spot08_BakudankabeSegmentRomStart[]; extern u8 _ovl_Bg_Spot08_BakudankabeSegmentRomEnd[];
extern u8 _ovl_Bg_Spot17_BakudankabeSegmentStart[]; extern u8 _ovl_Bg_Spot17_BakudankabeSegmentEnd[]; extern u8 _ovl_Bg_Spot17_BakudankabeSegmentRomStart[]; extern u8 _ovl_Bg_Spot17_BakudankabeSegmentRomEnd[];
extern u8 _ovl_Obj_Mure3SegmentStart[]; extern u8 _ovl_Obj_Mure3SegmentEnd[]; extern u8 _ovl_Obj_Mure3SegmentRomStart[]; extern u8 _ovl_Obj_Mure3SegmentRomEnd[];
extern u8 _ovl_En_TgSegmentStart[]; extern u8 _ovl_En_TgSegmentEnd[]; extern u8 _ovl_En_TgSegmentRomStart[]; extern u8 _ovl_En_TgSegmentRomEnd[];
extern u8 _ovl_En_MuSegmentStart[]; extern u8 _ovl_En_MuSegmentEnd[]; extern u8 _ovl_En_MuSegmentRomStart[]; extern u8 _ovl_En_MuSegmentRomEnd[];
extern u8 _ovl_En_Go2SegmentStart[]; extern u8 _ovl_En_Go2SegmentEnd[]; extern u8 _ovl_En_Go2SegmentRomStart[]; extern u8 _ovl_En_Go2SegmentRomEnd[];
extern u8 _ovl_En_WfSegmentStart[]; extern u8 _ovl_En_WfSegmentEnd[]; extern u8 _ovl_En_WfSegmentRomStart[]; extern u8 _ovl_En_WfSegmentRomEnd[];
extern u8 _ovl_En_SkbSegmentStart[]; extern u8 _ovl_En_SkbSegmentEnd[]; extern u8 _ovl_En_SkbSegmentRomStart[]; extern u8 _ovl_En_SkbSegmentRomEnd[];
extern u8 _ovl_Demo_GjSegmentStart[]; extern u8 _ovl_Demo_GjSegmentEnd[]; extern u8 _ovl_Demo_GjSegmentRomStart[]; extern u8 _ovl_Demo_GjSegmentRomEnd[];
extern u8 _ovl_Demo_GeffSegmentStart[]; extern u8 _ovl_Demo_GeffSegmentEnd[]; extern u8 _ovl_Demo_GeffSegmentRomStart[]; extern u8 _ovl_Demo_GeffSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_FiremeiroSegmentStart[]; extern u8 _ovl_Bg_Gnd_FiremeiroSegmentEnd[]; extern u8 _ovl_Bg_Gnd_FiremeiroSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_FiremeiroSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_DarkmeiroSegmentStart[]; extern u8 _ovl_Bg_Gnd_DarkmeiroSegmentEnd[]; extern u8 _ovl_Bg_Gnd_DarkmeiroSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_DarkmeiroSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_SoulmeiroSegmentStart[]; extern u8 _ovl_Bg_Gnd_SoulmeiroSegmentEnd[]; extern u8 _ovl_Bg_Gnd_SoulmeiroSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_SoulmeiroSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_NisekabeSegmentStart[]; extern u8 _ovl_Bg_Gnd_NisekabeSegmentEnd[]; extern u8 _ovl_Bg_Gnd_NisekabeSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_NisekabeSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_IceblockSegmentStart[]; extern u8 _ovl_Bg_Gnd_IceblockSegmentEnd[]; extern u8 _ovl_Bg_Gnd_IceblockSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_IceblockSegmentRomEnd[];
extern u8 _ovl_En_GbSegmentStart[]; extern u8 _ovl_En_GbSegmentEnd[]; extern u8 _ovl_En_GbSegmentRomStart[]; extern u8 _ovl_En_GbSegmentRomEnd[];
extern u8 _ovl_En_GsSegmentStart[]; extern u8 _ovl_En_GsSegmentEnd[]; extern u8 _ovl_En_GsSegmentRomStart[]; extern u8 _ovl_En_GsSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_BwallSegmentStart[]; extern u8 _ovl_Bg_Mizu_BwallSegmentEnd[]; extern u8 _ovl_Bg_Mizu_BwallSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_BwallSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_ShutterSegmentStart[]; extern u8 _ovl_Bg_Mizu_ShutterSegmentEnd[]; extern u8 _ovl_Bg_Mizu_ShutterSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_ShutterSegmentRomEnd[];
extern u8 _ovl_En_Daiku_KakarikoSegmentStart[]; extern u8 _ovl_En_Daiku_KakarikoSegmentEnd[]; extern u8 _ovl_En_Daiku_KakarikoSegmentRomStart[]; extern u8 _ovl_En_Daiku_KakarikoSegmentRomEnd[];
extern u8 _ovl_Bg_Bowl_WallSegmentStart[]; extern u8 _ovl_Bg_Bowl_WallSegmentEnd[]; extern u8 _ovl_Bg_Bowl_WallSegmentRomStart[]; extern u8 _ovl_Bg_Bowl_WallSegmentRomEnd[];
extern u8 _ovl_En_Wall_TuboSegmentStart[]; extern u8 _ovl_En_Wall_TuboSegmentEnd[]; extern u8 _ovl_En_Wall_TuboSegmentRomStart[]; extern u8 _ovl_En_Wall_TuboSegmentRomEnd[];
extern u8 _ovl_En_Po_DesertSegmentStart[]; extern u8 _ovl_En_Po_DesertSegmentEnd[]; extern u8 _ovl_En_Po_DesertSegmentRomStart[]; extern u8 _ovl_En_Po_DesertSegmentRomEnd[];
extern u8 _ovl_En_CrowSegmentStart[]; extern u8 _ovl_En_CrowSegmentEnd[]; extern u8 _ovl_En_CrowSegmentRomStart[]; extern u8 _ovl_En_CrowSegmentRomEnd[];
extern u8 _ovl_Door_KillerSegmentStart[]; extern u8 _ovl_Door_KillerSegmentEnd[]; extern u8 _ovl_Door_KillerSegmentRomStart[]; extern u8 _ovl_Door_KillerSegmentRomEnd[];
extern u8 _ovl_Bg_Spot11_OasisSegmentStart[]; extern u8 _ovl_Bg_Spot11_OasisSegmentEnd[]; extern u8 _ovl_Bg_Spot11_OasisSegmentRomStart[]; extern u8 _ovl_Bg_Spot11_OasisSegmentRomEnd[];
extern u8 _ovl_Bg_Spot18_FutaSegmentStart[]; extern u8 _ovl_Bg_Spot18_FutaSegmentEnd[]; extern u8 _ovl_Bg_Spot18_FutaSegmentRomStart[]; extern u8 _ovl_Bg_Spot18_FutaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot18_ShutterSegmentStart[]; extern u8 _ovl_Bg_Spot18_ShutterSegmentEnd[]; extern u8 _ovl_Bg_Spot18_ShutterSegmentRomStart[]; extern u8 _ovl_Bg_Spot18_ShutterSegmentRomEnd[];
extern u8 _ovl_En_Ma3SegmentStart[]; extern u8 _ovl_En_Ma3SegmentEnd[]; extern u8 _ovl_En_Ma3SegmentRomStart[]; extern u8 _ovl_En_Ma3SegmentRomEnd[];
extern u8 _ovl_En_CowSegmentStart[]; extern u8 _ovl_En_CowSegmentEnd[]; extern u8 _ovl_En_CowSegmentRomStart[]; extern u8 _ovl_En_CowSegmentRomEnd[];
extern u8 _ovl_Bg_Ice_TuraraSegmentStart[]; extern u8 _ovl_Bg_Ice_TuraraSegmentEnd[]; extern u8 _ovl_Bg_Ice_TuraraSegmentRomStart[]; extern u8 _ovl_Bg_Ice_TuraraSegmentRomEnd[];
extern u8 _ovl_Bg_Ice_ShutterSegmentStart[]; extern u8 _ovl_Bg_Ice_ShutterSegmentEnd[]; extern u8 _ovl_Bg_Ice_ShutterSegmentRomStart[]; extern u8 _ovl_Bg_Ice_ShutterSegmentRomEnd[];
extern u8 _ovl_En_Kakasi2SegmentStart[]; extern u8 _ovl_En_Kakasi2SegmentEnd[]; extern u8 _ovl_En_Kakasi2SegmentRomStart[]; extern u8 _ovl_En_Kakasi2SegmentRomEnd[];
extern u8 _ovl_En_Kakasi3SegmentStart[]; extern u8 _ovl_En_Kakasi3SegmentEnd[]; extern u8 _ovl_En_Kakasi3SegmentRomStart[]; extern u8 _ovl_En_Kakasi3SegmentRomEnd[];
extern u8 _ovl_Oceff_Wipe4SegmentStart[]; extern u8 _ovl_Oceff_Wipe4SegmentEnd[]; extern u8 _ovl_Oceff_Wipe4SegmentRomStart[]; extern u8 _ovl_Oceff_Wipe4SegmentRomEnd[];
extern u8 _ovl_En_EgSegmentStart[]; extern u8 _ovl_En_EgSegmentEnd[]; extern u8 _ovl_En_EgSegmentRomStart[]; extern u8 _ovl_En_EgSegmentRomEnd[];
extern u8 _ovl_Bg_Menkuri_NisekabeSegmentStart[]; extern u8 _ovl_Bg_Menkuri_NisekabeSegmentEnd[]; extern u8 _ovl_Bg_Menkuri_NisekabeSegmentRomStart[]; extern u8 _ovl_Bg_Menkuri_NisekabeSegmentRomEnd[];
extern u8 _ovl_En_ZoSegmentStart[]; extern u8 _ovl_En_ZoSegmentEnd[]; extern u8 _ovl_En_ZoSegmentRomStart[]; extern u8 _ovl_En_ZoSegmentRomEnd[];
extern u8 _ovl_Obj_MakekinsutaSegmentStart[]; extern u8 _ovl_Obj_MakekinsutaSegmentEnd[]; extern u8 _ovl_Obj_MakekinsutaSegmentRomStart[]; extern u8 _ovl_Obj_MakekinsutaSegmentRomEnd[];
extern u8 _ovl_En_Ge3SegmentStart[]; extern u8 _ovl_En_Ge3SegmentEnd[]; extern u8 _ovl_En_Ge3SegmentRomStart[]; extern u8 _ovl_En_Ge3SegmentRomEnd[];
extern u8 _ovl_Obj_TimeblockSegmentStart[]; extern u8 _ovl_Obj_TimeblockSegmentEnd[]; extern u8 _ovl_Obj_TimeblockSegmentRomStart[]; extern u8 _ovl_Obj_TimeblockSegmentRomEnd[];
extern u8 _ovl_Obj_HamishiSegmentStart[]; extern u8 _ovl_Obj_HamishiSegmentEnd[]; extern u8 _ovl_Obj_HamishiSegmentRomStart[]; extern u8 _ovl_Obj_HamishiSegmentRomEnd[];
extern u8 _ovl_En_Zl4SegmentStart[]; extern u8 _ovl_En_Zl4SegmentEnd[]; extern u8 _ovl_En_Zl4SegmentRomStart[]; extern u8 _ovl_En_Zl4SegmentRomEnd[];
extern u8 _ovl_En_Mm2SegmentStart[]; extern u8 _ovl_En_Mm2SegmentEnd[]; extern u8 _ovl_En_Mm2SegmentRomStart[]; extern u8 _ovl_En_Mm2SegmentRomEnd[];
extern u8 _ovl_Bg_Jya_BlockSegmentStart[]; extern u8 _ovl_Bg_Jya_BlockSegmentEnd[]; extern u8 _ovl_Bg_Jya_BlockSegmentRomStart[]; extern u8 _ovl_Bg_Jya_BlockSegmentRomEnd[];
extern u8 _ovl_Obj_Warp2blockSegmentStart[]; extern u8 _ovl_Obj_Warp2blockSegmentEnd[]; extern u8 _ovl_Obj_Warp2blockSegmentRomStart[]; extern u8 _ovl_Obj_Warp2blockSegmentRomEnd[];
extern u8 _gameplay_keepSegmentRomStart[]; extern u8 _gameplay_keepSegmentRomEnd[];
extern u8 _gameplay_field_keepSegmentRomStart[]; extern u8 _gameplay_field_keepSegmentRomEnd[];
extern u8 _gameplay_dangeon_keepSegmentRomStart[]; extern u8 _gameplay_dangeon_keepSegmentRomEnd[];
extern u8 _object_humanSegmentRomStart[]; extern u8 _object_humanSegmentRomEnd[];
extern u8 _object_okutaSegmentRomStart[]; extern u8 _object_okutaSegmentRomEnd[];
extern u8 _object_crowSegmentRomStart[]; extern u8 _object_crowSegmentRomEnd[];
extern u8 _object_pohSegmentRomStart[]; extern u8 _object_pohSegmentRomEnd[];
extern u8 _object_dy_objSegmentRomStart[]; extern u8 _object_dy_objSegmentRomEnd[];
extern u8 _object_wallmasterSegmentRomStart[]; extern u8 _object_wallmasterSegmentRomEnd[];
extern u8 _object_dodongoSegmentRomStart[]; extern u8 _object_dodongoSegmentRomEnd[];
extern u8 _object_fireflySegmentRomStart[]; extern u8 _object_fireflySegmentRomEnd[];
extern u8 _object_boxSegmentRomStart[]; extern u8 _object_boxSegmentRomEnd[];
extern u8 _object_fireSegmentRomStart[]; extern u8 _object_fireSegmentRomEnd[];
extern u8 _object_bubbleSegmentRomStart[]; extern u8 _object_bubbleSegmentRomEnd[];
extern u8 _object_niwSegmentRomStart[]; extern u8 _object_niwSegmentRomEnd[];
extern u8 _object_link_boySegmentRomStart[]; extern u8 _object_link_boySegmentRomEnd[];
extern u8 _object_link_childSegmentRomStart[]; extern u8 _object_link_childSegmentRomEnd[];
extern u8 _object_titeSegmentRomStart[]; extern u8 _object_titeSegmentRomEnd[];
extern u8 _object_reebaSegmentRomStart[]; extern u8 _object_reebaSegmentRomEnd[];
extern u8 _object_peehatSegmentRomStart[]; extern u8 _object_peehatSegmentRomEnd[];
extern u8 _object_kingdodongoSegmentRomStart[]; extern u8 _object_kingdodongoSegmentRomEnd[];
extern u8 _object_horseSegmentRomStart[]; extern u8 _object_horseSegmentRomEnd[];
extern u8 _object_zfSegmentRomStart[]; extern u8 _object_zfSegmentRomEnd[];
extern u8 _object_gomaSegmentRomStart[]; extern u8 _object_gomaSegmentRomEnd[];
extern u8 _object_zl1SegmentRomStart[]; extern u8 _object_zl1SegmentRomEnd[];
extern u8 _object_golSegmentRomStart[]; extern u8 _object_golSegmentRomEnd[];
extern u8 _object_dodojrSegmentRomStart[]; extern u8 _object_dodojrSegmentRomEnd[];
extern u8 _object_torch2SegmentRomStart[]; extern u8 _object_torch2SegmentRomEnd[];
extern u8 _object_blSegmentRomStart[]; extern u8 _object_blSegmentRomEnd[];
extern u8 _object_tpSegmentRomStart[]; extern u8 _object_tpSegmentRomEnd[];
extern u8 _object_oA1SegmentRomStart[]; extern u8 _object_oA1SegmentRomEnd[];
extern u8 _object_stSegmentRomStart[]; extern u8 _object_stSegmentRomEnd[];
extern u8 _object_bwSegmentRomStart[]; extern u8 _object_bwSegmentRomEnd[];
extern u8 _object_eiSegmentRomStart[]; extern u8 _object_eiSegmentRomEnd[];
extern u8 _object_horse_normalSegmentRomStart[]; extern u8 _object_horse_normalSegmentRomEnd[];
extern u8 _object_oB1SegmentRomStart[]; extern u8 _object_oB1SegmentRomEnd[];
extern u8 _object_o_animeSegmentRomStart[]; extern u8 _object_o_animeSegmentRomEnd[];
extern u8 _object_spot04_objectsSegmentRomStart[]; extern u8 _object_spot04_objectsSegmentRomEnd[];
extern u8 _object_ddan_objectsSegmentRomStart[]; extern u8 _object_ddan_objectsSegmentRomEnd[];
extern u8 _object_hidan_objectsSegmentRomStart[]; extern u8 _object_hidan_objectsSegmentRomEnd[];
extern u8 _object_horse_ganonSegmentRomStart[]; extern u8 _object_horse_ganonSegmentRomEnd[];
extern u8 _object_oA2SegmentRomStart[]; extern u8 _object_oA2SegmentRomEnd[];
extern u8 _object_spot00_objectsSegmentRomStart[]; extern u8 _object_spot00_objectsSegmentRomEnd[];
extern u8 _object_mbSegmentRomStart[]; extern u8 _object_mbSegmentRomEnd[];
extern u8 _object_bombfSegmentRomStart[]; extern u8 _object_bombfSegmentRomEnd[];
extern u8 _object_sk2SegmentRomStart[]; extern u8 _object_sk2SegmentRomEnd[];
extern u8 _object_oE1SegmentRomStart[]; extern u8 _object_oE1SegmentRomEnd[];
extern u8 _object_oE_animeSegmentRomStart[]; extern u8 _object_oE_animeSegmentRomEnd[];
extern u8 _object_oE2SegmentRomStart[]; extern u8 _object_oE2SegmentRomEnd[];
extern u8 _object_ydan_objectsSegmentRomStart[]; extern u8 _object_ydan_objectsSegmentRomEnd[];
extern u8 _object_gndSegmentRomStart[]; extern u8 _object_gndSegmentRomEnd[];
extern u8 _object_amSegmentRomStart[]; extern u8 _object_amSegmentRomEnd[];
extern u8 _object_dekubabaSegmentRomStart[]; extern u8 _object_dekubabaSegmentRomEnd[];
extern u8 _object_oA3SegmentRomStart[]; extern u8 _object_oA3SegmentRomEnd[];
extern u8 _object_oA4SegmentRomStart[]; extern u8 _object_oA4SegmentRomEnd[];
extern u8 _object_oA5SegmentRomStart[]; extern u8 _object_oA5SegmentRomEnd[];
extern u8 _object_oA6SegmentRomStart[]; extern u8 _object_oA6SegmentRomEnd[];
extern u8 _object_oA7SegmentRomStart[]; extern u8 _object_oA7SegmentRomEnd[];
extern u8 _object_jjSegmentRomStart[]; extern u8 _object_jjSegmentRomEnd[];
extern u8 _object_oA8SegmentRomStart[]; extern u8 _object_oA8SegmentRomEnd[];
extern u8 _object_oA9SegmentRomStart[]; extern u8 _object_oA9SegmentRomEnd[];
extern u8 _object_oB2SegmentRomStart[]; extern u8 _object_oB2SegmentRomEnd[];
extern u8 _object_oB3SegmentRomStart[]; extern u8 _object_oB3SegmentRomEnd[];
extern u8 _object_oB4SegmentRomStart[]; extern u8 _object_oB4SegmentRomEnd[];
extern u8 _object_horse_zeldaSegmentRomStart[]; extern u8 _object_horse_zeldaSegmentRomEnd[];
extern u8 _object_opening_demo1SegmentRomStart[]; extern u8 _object_opening_demo1SegmentRomEnd[];
extern u8 _object_warp1SegmentRomStart[]; extern u8 _object_warp1SegmentRomEnd[];
extern u8 _object_b_heartSegmentRomStart[]; extern u8 _object_b_heartSegmentRomEnd[];
extern u8 _object_dekunutsSegmentRomStart[]; extern u8 _object_dekunutsSegmentRomEnd[];
extern u8 _object_oE3SegmentRomStart[]; extern u8 _object_oE3SegmentRomEnd[];
extern u8 _object_oE4SegmentRomStart[]; extern u8 _object_oE4SegmentRomEnd[];
extern u8 _object_menkuri_objectsSegmentRomStart[]; extern u8 _object_menkuri_objectsSegmentRomEnd[];
extern u8 _object_oE5SegmentRomStart[]; extern u8 _object_oE5SegmentRomEnd[];
extern u8 _object_oE6SegmentRomStart[]; extern u8 _object_oE6SegmentRomEnd[];
extern u8 _object_oE7SegmentRomStart[]; extern u8 _object_oE7SegmentRomEnd[];
extern u8 _object_oE8SegmentRomStart[]; extern u8 _object_oE8SegmentRomEnd[];
extern u8 _object_oE9SegmentRomStart[]; extern u8 _object_oE9SegmentRomEnd[];
extern u8 _object_oE10SegmentRomStart[]; extern u8 _object_oE10SegmentRomEnd[];
extern u8 _object_oE11SegmentRomStart[]; extern u8 _object_oE11SegmentRomEnd[];
extern u8 _object_oE12SegmentRomStart[]; extern u8 _object_oE12SegmentRomEnd[];
extern u8 _object_valiSegmentRomStart[]; extern u8 _object_valiSegmentRomEnd[];
extern u8 _object_oA10SegmentRomStart[]; extern u8 _object_oA10SegmentRomEnd[];
extern u8 _object_oA11SegmentRomStart[]; extern u8 _object_oA11SegmentRomEnd[];
extern u8 _object_mizu_objectsSegmentRomStart[]; extern u8 _object_mizu_objectsSegmentRomEnd[];
extern u8 _object_fhgSegmentRomStart[]; extern u8 _object_fhgSegmentRomEnd[];
extern u8 _object_ossanSegmentRomStart[]; extern u8 _object_ossanSegmentRomEnd[];
extern u8 _object_mori_hineri1SegmentRomStart[]; extern u8 _object_mori_hineri1SegmentRomEnd[];
extern u8 _object_BbSegmentRomStart[]; extern u8 _object_BbSegmentRomEnd[];
extern u8 _object_toki_objectsSegmentRomStart[]; extern u8 _object_toki_objectsSegmentRomEnd[];
extern u8 _object_yukabyunSegmentRomStart[]; extern u8 _object_yukabyunSegmentRomEnd[];
extern u8 _object_zl2SegmentRomStart[]; extern u8 _object_zl2SegmentRomEnd[];
extern u8 _object_mjinSegmentRomStart[]; extern u8 _object_mjinSegmentRomEnd[];
extern u8 _object_mjin_flashSegmentRomStart[]; extern u8 _object_mjin_flashSegmentRomEnd[];
extern u8 _object_mjin_darkSegmentRomStart[]; extern u8 _object_mjin_darkSegmentRomEnd[];
extern u8 _object_mjin_flameSegmentRomStart[]; extern u8 _object_mjin_flameSegmentRomEnd[];
extern u8 _object_mjin_iceSegmentRomStart[]; extern u8 _object_mjin_iceSegmentRomEnd[];
extern u8 _object_mjin_soulSegmentRomStart[]; extern u8 _object_mjin_soulSegmentRomEnd[];
extern u8 _object_mjin_windSegmentRomStart[]; extern u8 _object_mjin_windSegmentRomEnd[];
extern u8 _object_mjin_okaSegmentRomStart[]; extern u8 _object_mjin_okaSegmentRomEnd[];
extern u8 _object_haka_objectsSegmentRomStart[]; extern u8 _object_haka_objectsSegmentRomEnd[];
extern u8 _object_spot06_objectsSegmentRomStart[]; extern u8 _object_spot06_objectsSegmentRomEnd[];
extern u8 _object_ice_objectsSegmentRomStart[]; extern u8 _object_ice_objectsSegmentRomEnd[];
extern u8 _object_relay_objectsSegmentRomStart[]; extern u8 _object_relay_objectsSegmentRomEnd[];
extern u8 _object_po_fieldSegmentRomStart[]; extern u8 _object_po_fieldSegmentRomEnd[];
extern u8 _object_po_composerSegmentRomStart[]; extern u8 _object_po_composerSegmentRomEnd[];
extern u8 _object_mori_hineri1aSegmentRomStart[]; extern u8 _object_mori_hineri1aSegmentRomEnd[];
extern u8 _object_mori_hineri2SegmentRomStart[]; extern u8 _object_mori_hineri2SegmentRomEnd[];
extern u8 _object_mori_hineri2aSegmentRomStart[]; extern u8 _object_mori_hineri2aSegmentRomEnd[];
extern u8 _object_mori_objectsSegmentRomStart[]; extern u8 _object_mori_objectsSegmentRomEnd[];
extern u8 _object_mori_texSegmentRomStart[]; extern u8 _object_mori_texSegmentRomEnd[];
extern u8 _object_spot08_objSegmentRomStart[]; extern u8 _object_spot08_objSegmentRomEnd[];
extern u8 _object_warp2SegmentRomStart[]; extern u8 _object_warp2SegmentRomEnd[];
extern u8 _object_hataSegmentRomStart[]; extern u8 _object_hataSegmentRomEnd[];
extern u8 _object_birdSegmentRomStart[]; extern u8 _object_birdSegmentRomEnd[];
extern u8 _object_wood02SegmentRomStart[]; extern u8 _object_wood02SegmentRomEnd[];
extern u8 _object_lightboxSegmentRomStart[]; extern u8 _object_lightboxSegmentRomEnd[];
extern u8 _object_pu_boxSegmentRomStart[]; extern u8 _object_pu_boxSegmentRomEnd[];
extern u8 _object_trapSegmentRomStart[]; extern u8 _object_trapSegmentRomEnd[];
extern u8 _object_vaseSegmentRomStart[]; extern u8 _object_vaseSegmentRomEnd[];
extern u8 _object_imSegmentRomStart[]; extern u8 _object_imSegmentRomEnd[];
extern u8 _object_taSegmentRomStart[]; extern u8 _object_taSegmentRomEnd[];
extern u8 _object_tkSegmentRomStart[]; extern u8 _object_tkSegmentRomEnd[];
extern u8 _object_xcSegmentRomStart[]; extern u8 _object_xcSegmentRomEnd[];
extern u8 _object_vmSegmentRomStart[]; extern u8 _object_vmSegmentRomEnd[];
extern u8 _object_bvSegmentRomStart[]; extern u8 _object_bvSegmentRomEnd[];
extern u8 _object_hakach_objectsSegmentRomStart[]; extern u8 _object_hakach_objectsSegmentRomEnd[];
extern u8 _object_efc_crystal_lightSegmentRomStart[]; extern u8 _object_efc_crystal_lightSegmentRomEnd[];
extern u8 _object_efc_fire_ballSegmentRomStart[]; extern u8 _object_efc_fire_ballSegmentRomEnd[];
extern u8 _object_efc_flashSegmentRomStart[]; extern u8 _object_efc_flashSegmentRomEnd[];
extern u8 _object_efc_lgt_showerSegmentRomStart[]; extern u8 _object_efc_lgt_showerSegmentRomEnd[];
extern u8 _object_efc_star_fieldSegmentRomStart[]; extern u8 _object_efc_star_fieldSegmentRomEnd[];
extern u8 _object_god_lgtSegmentRomStart[]; extern u8 _object_god_lgtSegmentRomEnd[];
extern u8 _object_light_ringSegmentRomStart[]; extern u8 _object_light_ringSegmentRomEnd[];
extern u8 _object_triforce_spotSegmentRomStart[]; extern u8 _object_triforce_spotSegmentRomEnd[];
extern u8 _object_bdan_objectsSegmentRomStart[]; extern u8 _object_bdan_objectsSegmentRomEnd[];
extern u8 _object_sdSegmentRomStart[]; extern u8 _object_sdSegmentRomEnd[];
extern u8 _object_rdSegmentRomStart[]; extern u8 _object_rdSegmentRomEnd[];
extern u8 _object_po_sistersSegmentRomStart[]; extern u8 _object_po_sistersSegmentRomEnd[];
extern u8 _object_heavy_objectSegmentRomStart[]; extern u8 _object_heavy_objectSegmentRomEnd[];
extern u8 _object_gnddSegmentRomStart[]; extern u8 _object_gnddSegmentRomEnd[];
extern u8 _object_fdSegmentRomStart[]; extern u8 _object_fdSegmentRomEnd[];
extern u8 _object_duSegmentRomStart[]; extern u8 _object_duSegmentRomEnd[];
extern u8 _object_fwSegmentRomStart[]; extern u8 _object_fwSegmentRomEnd[];
extern u8 _object_medalSegmentRomStart[]; extern u8 _object_medalSegmentRomEnd[];
extern u8 _object_horse_link_childSegmentRomStart[]; extern u8 _object_horse_link_childSegmentRomEnd[];
extern u8 _object_spot02_objectsSegmentRomStart[]; extern u8 _object_spot02_objectsSegmentRomEnd[];
extern u8 _object_hakaSegmentRomStart[]; extern u8 _object_hakaSegmentRomEnd[];
extern u8 _object_ru1SegmentRomStart[]; extern u8 _object_ru1SegmentRomEnd[];
extern u8 _object_syokudaiSegmentRomStart[]; extern u8 _object_syokudaiSegmentRomEnd[];
extern u8 _object_fd2SegmentRomStart[]; extern u8 _object_fd2SegmentRomEnd[];
extern u8 _object_dhSegmentRomStart[]; extern u8 _object_dhSegmentRomEnd[];
extern u8 _object_rlSegmentRomStart[]; extern u8 _object_rlSegmentRomEnd[];
extern u8 _object_efc_twSegmentRomStart[]; extern u8 _object_efc_twSegmentRomEnd[];
extern u8 _object_demo_tre_lgtSegmentRomStart[]; extern u8 _object_demo_tre_lgtSegmentRomEnd[];
extern u8 _object_gi_keySegmentRomStart[]; extern u8 _object_gi_keySegmentRomEnd[];
extern u8 _object_mir_raySegmentRomStart[]; extern u8 _object_mir_raySegmentRomEnd[];
extern u8 _object_brobSegmentRomStart[]; extern u8 _object_brobSegmentRomEnd[];
extern u8 _object_gi_jewelSegmentRomStart[]; extern u8 _object_gi_jewelSegmentRomEnd[];
extern u8 _object_spot09_objSegmentRomStart[]; extern u8 _object_spot09_objSegmentRomEnd[];
extern u8 _object_spot18_objSegmentRomStart[]; extern u8 _object_spot18_objSegmentRomEnd[];
extern u8 _object_bdoorSegmentRomStart[]; extern u8 _object_bdoorSegmentRomEnd[];
extern u8 _object_spot17_objSegmentRomStart[]; extern u8 _object_spot17_objSegmentRomEnd[];
extern u8 _object_shop_dungenSegmentRomStart[]; extern u8 _object_shop_dungenSegmentRomEnd[];
extern u8 _object_nbSegmentRomStart[]; extern u8 _object_nbSegmentRomEnd[];
extern u8 _object_moSegmentRomStart[]; extern u8 _object_moSegmentRomEnd[];
extern u8 _object_sbSegmentRomStart[]; extern u8 _object_sbSegmentRomEnd[];
extern u8 _object_gi_melodySegmentRomStart[]; extern u8 _object_gi_melodySegmentRomEnd[];
extern u8 _object_gi_heartSegmentRomStart[]; extern u8 _object_gi_heartSegmentRomEnd[];
extern u8 _object_gi_compassSegmentRomStart[]; extern u8 _object_gi_compassSegmentRomEnd[];
extern u8 _object_gi_bosskeySegmentRomStart[]; extern u8 _object_gi_bosskeySegmentRomEnd[];
extern u8 _object_gi_medalSegmentRomStart[]; extern u8 _object_gi_medalSegmentRomEnd[];
extern u8 _object_gi_nutsSegmentRomStart[]; extern u8 _object_gi_nutsSegmentRomEnd[];
extern u8 _object_saSegmentRomStart[]; extern u8 _object_saSegmentRomEnd[];
extern u8 _object_gi_heartsSegmentRomStart[]; extern u8 _object_gi_heartsSegmentRomEnd[];
extern u8 _object_gi_arrowcaseSegmentRomStart[]; extern u8 _object_gi_arrowcaseSegmentRomEnd[];
extern u8 _object_gi_bombpouchSegmentRomStart[]; extern u8 _object_gi_bombpouchSegmentRomEnd[];
extern u8 _object_inSegmentRomStart[]; extern u8 _object_inSegmentRomEnd[];
extern u8 _object_trSegmentRomStart[]; extern u8 _object_trSegmentRomEnd[];
extern u8 _object_spot16_objSegmentRomStart[]; extern u8 _object_spot16_objSegmentRomEnd[];
extern u8 _object_oE1sSegmentRomStart[]; extern u8 _object_oE1sSegmentRomEnd[];
extern u8 _object_oE4sSegmentRomStart[]; extern u8 _object_oE4sSegmentRomEnd[];
extern u8 _object_os_animeSegmentRomStart[]; extern u8 _object_os_animeSegmentRomEnd[];
extern u8 _object_gi_bottleSegmentRomStart[]; extern u8 _object_gi_bottleSegmentRomEnd[];
extern u8 _object_gi_stickSegmentRomStart[]; extern u8 _object_gi_stickSegmentRomEnd[];
extern u8 _object_gi_mapSegmentRomStart[]; extern u8 _object_gi_mapSegmentRomEnd[];
extern u8 _object_oF1d_mapSegmentRomStart[]; extern u8 _object_oF1d_mapSegmentRomEnd[];
extern u8 _object_ru2SegmentRomStart[]; extern u8 _object_ru2SegmentRomEnd[];
extern u8 _object_gi_shield_1SegmentRomStart[]; extern u8 _object_gi_shield_1SegmentRomEnd[];
extern u8 _object_dekujrSegmentRomStart[]; extern u8 _object_dekujrSegmentRomEnd[];
extern u8 _object_gi_magicpotSegmentRomStart[]; extern u8 _object_gi_magicpotSegmentRomEnd[];
extern u8 _object_gi_bomb_1SegmentRomStart[]; extern u8 _object_gi_bomb_1SegmentRomEnd[];
extern u8 _object_oF1sSegmentRomStart[]; extern u8 _object_oF1sSegmentRomEnd[];
extern u8 _object_ma2SegmentRomStart[]; extern u8 _object_ma2SegmentRomEnd[];
extern u8 _object_gi_purseSegmentRomStart[]; extern u8 _object_gi_purseSegmentRomEnd[];
extern u8 _object_hniSegmentRomStart[]; extern u8 _object_hniSegmentRomEnd[];
extern u8 _object_twSegmentRomStart[]; extern u8 _object_twSegmentRomEnd[];
extern u8 _object_rrSegmentRomStart[]; extern u8 _object_rrSegmentRomEnd[];
extern u8 _object_bxaSegmentRomStart[]; extern u8 _object_bxaSegmentRomEnd[];
extern u8 _object_anubiceSegmentRomStart[]; extern u8 _object_anubiceSegmentRomEnd[];
extern u8 _object_gi_gerudoSegmentRomStart[]; extern u8 _object_gi_gerudoSegmentRomEnd[];
extern u8 _object_gi_arrowSegmentRomStart[]; extern u8 _object_gi_arrowSegmentRomEnd[];
extern u8 _object_gi_bomb_2SegmentRomStart[]; extern u8 _object_gi_bomb_2SegmentRomEnd[];
extern u8 _object_gi_eggSegmentRomStart[]; extern u8 _object_gi_eggSegmentRomEnd[];
extern u8 _object_gi_scaleSegmentRomStart[]; extern u8 _object_gi_scaleSegmentRomEnd[];
extern u8 _object_gi_shield_2SegmentRomStart[]; extern u8 _object_gi_shield_2SegmentRomEnd[];
extern u8 _object_gi_hookshotSegmentRomStart[]; extern u8 _object_gi_hookshotSegmentRomEnd[];
extern u8 _object_gi_ocarinaSegmentRomStart[]; extern u8 _object_gi_ocarinaSegmentRomEnd[];
extern u8 _object_gi_milkSegmentRomStart[]; extern u8 _object_gi_milkSegmentRomEnd[];
extern u8 _object_ma1SegmentRomStart[]; extern u8 _object_ma1SegmentRomEnd[];
extern u8 _object_ganonSegmentRomStart[]; extern u8 _object_ganonSegmentRomEnd[];
extern u8 _object_sstSegmentRomStart[]; extern u8 _object_sstSegmentRomEnd[];
extern u8 _object_nySegmentRomStart[]; extern u8 _object_nySegmentRomEnd[];
extern u8 _object_nySegmentRomStart[]; extern u8 _object_nySegmentRomEnd[];
extern u8 _object_frSegmentRomStart[]; extern u8 _object_frSegmentRomEnd[];
extern u8 _object_gi_pachinkoSegmentRomStart[]; extern u8 _object_gi_pachinkoSegmentRomEnd[];
extern u8 _object_gi_boomerangSegmentRomStart[]; extern u8 _object_gi_boomerangSegmentRomEnd[];
extern u8 _object_gi_bowSegmentRomStart[]; extern u8 _object_gi_bowSegmentRomEnd[];
extern u8 _object_gi_glassesSegmentRomStart[]; extern u8 _object_gi_glassesSegmentRomEnd[];
extern u8 _object_gi_liquidSegmentRomStart[]; extern u8 _object_gi_liquidSegmentRomEnd[];
extern u8 _object_aniSegmentRomStart[]; extern u8 _object_aniSegmentRomEnd[];
extern u8 _object_demo_6kSegmentRomStart[]; extern u8 _object_demo_6kSegmentRomEnd[];
extern u8 _object_gi_shield_3SegmentRomStart[]; extern u8 _object_gi_shield_3SegmentRomEnd[];
extern u8 _object_gi_letterSegmentRomStart[]; extern u8 _object_gi_letterSegmentRomEnd[];
extern u8 _object_spot15_objSegmentRomStart[]; extern u8 _object_spot15_objSegmentRomEnd[];
extern u8 _object_jya_objSegmentRomStart[]; extern u8 _object_jya_objSegmentRomEnd[];
extern u8 _object_gi_clothesSegmentRomStart[]; extern u8 _object_gi_clothesSegmentRomEnd[];
extern u8 _object_gi_beanSegmentRomStart[]; extern u8 _object_gi_beanSegmentRomEnd[];
extern u8 _object_gi_fishSegmentRomStart[]; extern u8 _object_gi_fishSegmentRomEnd[];
extern u8 _object_gi_sawSegmentRomStart[]; extern u8 _object_gi_sawSegmentRomEnd[];
extern u8 _object_gi_hammerSegmentRomStart[]; extern u8 _object_gi_hammerSegmentRomEnd[];
extern u8 _object_gi_grassSegmentRomStart[]; extern u8 _object_gi_grassSegmentRomEnd[];
extern u8 _object_gi_longswordSegmentRomStart[]; extern u8 _object_gi_longswordSegmentRomEnd[];
extern u8 _object_spot01_objectsSegmentRomStart[]; extern u8 _object_spot01_objectsSegmentRomEnd[];
extern u8 _object_mdSegmentRomStart[]; extern u8 _object_mdSegmentRomEnd[];
extern u8 _object_mdSegmentRomStart[]; extern u8 _object_mdSegmentRomEnd[];
extern u8 _object_km1SegmentRomStart[]; extern u8 _object_km1SegmentRomEnd[];
extern u8 _object_kw1SegmentRomStart[]; extern u8 _object_kw1SegmentRomEnd[];
extern u8 _object_zoSegmentRomStart[]; extern u8 _object_zoSegmentRomEnd[];
extern u8 _object_kzSegmentRomStart[]; extern u8 _object_kzSegmentRomEnd[];
extern u8 _object_umajumpSegmentRomStart[]; extern u8 _object_umajumpSegmentRomEnd[];
extern u8 _object_masterkokiriSegmentRomStart[]; extern u8 _object_masterkokiriSegmentRomEnd[];
extern u8 _object_masterkokiriheadSegmentRomStart[]; extern u8 _object_masterkokiriheadSegmentRomEnd[];
extern u8 _object_mastergolonSegmentRomStart[]; extern u8 _object_mastergolonSegmentRomEnd[];
extern u8 _object_masterzooraSegmentRomStart[]; extern u8 _object_masterzooraSegmentRomEnd[];
extern u8 _object_aobSegmentRomStart[]; extern u8 _object_aobSegmentRomEnd[];
extern u8 _object_ikSegmentRomStart[]; extern u8 _object_ikSegmentRomEnd[];
extern u8 _object_ahgSegmentRomStart[]; extern u8 _object_ahgSegmentRomEnd[];
extern u8 _object_cneSegmentRomStart[]; extern u8 _object_cneSegmentRomEnd[];
extern u8 _object_gi_niwatoriSegmentRomStart[]; extern u8 _object_gi_niwatoriSegmentRomEnd[];
extern u8 _object_skjSegmentRomStart[]; extern u8 _object_skjSegmentRomEnd[];
extern u8 _object_gi_bottle_letterSegmentRomStart[]; extern u8 _object_gi_bottle_letterSegmentRomEnd[];
extern u8 _object_bjiSegmentRomStart[]; extern u8 _object_bjiSegmentRomEnd[];
extern u8 _object_bbaSegmentRomStart[]; extern u8 _object_bbaSegmentRomEnd[];
extern u8 _object_gi_ocarina_0SegmentRomStart[]; extern u8 _object_gi_ocarina_0SegmentRomEnd[];
extern u8 _object_dsSegmentRomStart[]; extern u8 _object_dsSegmentRomEnd[];
extern u8 _object_aneSegmentRomStart[]; extern u8 _object_aneSegmentRomEnd[];
extern u8 _object_bojSegmentRomStart[]; extern u8 _object_bojSegmentRomEnd[];
extern u8 _object_spot03_objectSegmentRomStart[]; extern u8 _object_spot03_objectSegmentRomEnd[];
extern u8 _object_spot07_objectSegmentRomStart[]; extern u8 _object_spot07_objectSegmentRomEnd[];
extern u8 _object_fzSegmentRomStart[]; extern u8 _object_fzSegmentRomEnd[];
extern u8 _object_bobSegmentRomStart[]; extern u8 _object_bobSegmentRomEnd[];
extern u8 _object_ge1SegmentRomStart[]; extern u8 _object_ge1SegmentRomEnd[];
extern u8 _object_yabusame_pointSegmentRomStart[]; extern u8 _object_yabusame_pointSegmentRomEnd[];
extern u8 _object_gi_boots_2SegmentRomStart[]; extern u8 _object_gi_boots_2SegmentRomEnd[];
extern u8 _object_gi_seedSegmentRomStart[]; extern u8 _object_gi_seedSegmentRomEnd[];
extern u8 _object_gnd_magicSegmentRomStart[]; extern u8 _object_gnd_magicSegmentRomEnd[];
extern u8 _object_d_elevatorSegmentRomStart[]; extern u8 _object_d_elevatorSegmentRomEnd[];
extern u8 _object_d_hsblockSegmentRomStart[]; extern u8 _object_d_hsblockSegmentRomEnd[];
extern u8 _object_d_liftSegmentRomStart[]; extern u8 _object_d_liftSegmentRomEnd[];
extern u8 _object_mamenokiSegmentRomStart[]; extern u8 _object_mamenokiSegmentRomEnd[];
extern u8 _object_goroiwaSegmentRomStart[]; extern u8 _object_goroiwaSegmentRomEnd[];
extern u8 _object_toryoSegmentRomStart[]; extern u8 _object_toryoSegmentRomEnd[];
extern u8 _object_daikuSegmentRomStart[]; extern u8 _object_daikuSegmentRomEnd[];
extern u8 _object_nwcSegmentRomStart[]; extern u8 _object_nwcSegmentRomEnd[];
extern u8 _object_blkobjSegmentRomStart[]; extern u8 _object_blkobjSegmentRomEnd[];
extern u8 _object_gmSegmentRomStart[]; extern u8 _object_gmSegmentRomEnd[];
extern u8 _object_msSegmentRomStart[]; extern u8 _object_msSegmentRomEnd[];
extern u8 _object_hsSegmentRomStart[]; extern u8 _object_hsSegmentRomEnd[];
extern u8 _object_ingateSegmentRomStart[]; extern u8 _object_ingateSegmentRomEnd[];
extern u8 _object_lightswitchSegmentRomStart[]; extern u8 _object_lightswitchSegmentRomEnd[];
extern u8 _object_kusaSegmentRomStart[]; extern u8 _object_kusaSegmentRomEnd[];
extern u8 _object_tsuboSegmentRomStart[]; extern u8 _object_tsuboSegmentRomEnd[];
extern u8 _object_gi_glovesSegmentRomStart[]; extern u8 _object_gi_glovesSegmentRomEnd[];
extern u8 _object_gi_coinSegmentRomStart[]; extern u8 _object_gi_coinSegmentRomEnd[];
extern u8 _object_kanbanSegmentRomStart[]; extern u8 _object_kanbanSegmentRomEnd[];
extern u8 _object_gjyo_objectsSegmentRomStart[]; extern u8 _object_gjyo_objectsSegmentRomEnd[];
extern u8 _object_owlSegmentRomStart[]; extern u8 _object_owlSegmentRomEnd[];
extern u8 _object_mkSegmentRomStart[]; extern u8 _object_mkSegmentRomEnd[];
extern u8 _object_fuSegmentRomStart[]; extern u8 _object_fuSegmentRomEnd[];
extern u8 _object_gi_ki_tan_maskSegmentRomStart[]; extern u8 _object_gi_ki_tan_maskSegmentRomEnd[];
extern u8 _object_gi_redead_maskSegmentRomStart[]; extern u8 _object_gi_redead_maskSegmentRomEnd[];
extern u8 _object_gi_skj_maskSegmentRomStart[]; extern u8 _object_gi_skj_maskSegmentRomEnd[];
extern u8 _object_gi_rabit_maskSegmentRomStart[]; extern u8 _object_gi_rabit_maskSegmentRomEnd[];
extern u8 _object_gi_truth_maskSegmentRomStart[]; extern u8 _object_gi_truth_maskSegmentRomEnd[];
extern u8 _object_ganon_objectsSegmentRomStart[]; extern u8 _object_ganon_objectsSegmentRomEnd[];
extern u8 _object_siofukiSegmentRomStart[]; extern u8 _object_siofukiSegmentRomEnd[];
extern u8 _object_streamSegmentRomStart[]; extern u8 _object_streamSegmentRomEnd[];
extern u8 _object_mmSegmentRomStart[]; extern u8 _object_mmSegmentRomEnd[];
extern u8 _object_faSegmentRomStart[]; extern u8 _object_faSegmentRomEnd[];
extern u8 _object_osSegmentRomStart[]; extern u8 _object_osSegmentRomEnd[];
extern u8 _object_gi_eye_lotionSegmentRomStart[]; extern u8 _object_gi_eye_lotionSegmentRomEnd[];
extern u8 _object_gi_powderSegmentRomStart[]; extern u8 _object_gi_powderSegmentRomEnd[];
extern u8 _object_gi_mushroomSegmentRomStart[]; extern u8 _object_gi_mushroomSegmentRomEnd[];
extern u8 _object_gi_ticketstoneSegmentRomStart[]; extern u8 _object_gi_ticketstoneSegmentRomEnd[];
extern u8 _object_gi_brokenswordSegmentRomStart[]; extern u8 _object_gi_brokenswordSegmentRomEnd[];
extern u8 _object_jsSegmentRomStart[]; extern u8 _object_jsSegmentRomEnd[];
extern u8 _object_csSegmentRomStart[]; extern u8 _object_csSegmentRomEnd[];
extern u8 _object_gi_prescriptionSegmentRomStart[]; extern u8 _object_gi_prescriptionSegmentRomEnd[];
extern u8 _object_gi_braceletSegmentRomStart[]; extern u8 _object_gi_braceletSegmentRomEnd[];
extern u8 _object_gi_soldoutSegmentRomStart[]; extern u8 _object_gi_soldoutSegmentRomEnd[];
extern u8 _object_gi_frogSegmentRomStart[]; extern u8 _object_gi_frogSegmentRomEnd[];
extern u8 _object_magSegmentRomStart[]; extern u8 _object_magSegmentRomEnd[];
extern u8 _object_door_gerudoSegmentRomStart[]; extern u8 _object_door_gerudoSegmentRomEnd[];
extern u8 _object_gtSegmentRomStart[]; extern u8 _object_gtSegmentRomEnd[];
extern u8 _object_efc_erupcSegmentRomStart[]; extern u8 _object_efc_erupcSegmentRomEnd[];
extern u8 _object_zl2_anime1SegmentRomStart[]; extern u8 _object_zl2_anime1SegmentRomEnd[];
extern u8 _object_zl2_anime2SegmentRomStart[]; extern u8 _object_zl2_anime2SegmentRomEnd[];
extern u8 _object_gi_golonmaskSegmentRomStart[]; extern u8 _object_gi_golonmaskSegmentRomEnd[];
extern u8 _object_gi_zoramaskSegmentRomStart[]; extern u8 _object_gi_zoramaskSegmentRomEnd[];
extern u8 _object_gi_gerudomaskSegmentRomStart[]; extern u8 _object_gi_gerudomaskSegmentRomEnd[];
extern u8 _object_ganon2SegmentRomStart[]; extern u8 _object_ganon2SegmentRomEnd[];
extern u8 _object_kaSegmentRomStart[]; extern u8 _object_kaSegmentRomEnd[];
extern u8 _object_tsSegmentRomStart[]; extern u8 _object_tsSegmentRomEnd[];
extern u8 _object_zgSegmentRomStart[]; extern u8 _object_zgSegmentRomEnd[];
extern u8 _object_gi_hoverbootsSegmentRomStart[]; extern u8 _object_gi_hoverbootsSegmentRomEnd[];
extern u8 _object_gi_m_arrowSegmentRomStart[]; extern u8 _object_gi_m_arrowSegmentRomEnd[];
extern u8 _object_ds2SegmentRomStart[]; extern u8 _object_ds2SegmentRomEnd[];
extern u8 _object_ecSegmentRomStart[]; extern u8 _object_ecSegmentRomEnd[];
extern u8 _object_fishSegmentRomStart[]; extern u8 _object_fishSegmentRomEnd[];
extern u8 _object_gi_sutaruSegmentRomStart[]; extern u8 _object_gi_sutaruSegmentRomEnd[];
extern u8 _object_gi_goddessSegmentRomStart[]; extern u8 _object_gi_goddessSegmentRomEnd[];
extern u8 _object_sshSegmentRomStart[]; extern u8 _object_sshSegmentRomEnd[];
extern u8 _object_bigokutaSegmentRomStart[]; extern u8 _object_bigokutaSegmentRomEnd[];
extern u8 _object_bgSegmentRomStart[]; extern u8 _object_bgSegmentRomEnd[];
extern u8 _object_spot05_objectsSegmentRomStart[]; extern u8 _object_spot05_objectsSegmentRomEnd[];
extern u8 _object_spot12_objSegmentRomStart[]; extern u8 _object_spot12_objSegmentRomEnd[];
extern u8 _object_bombiwaSegmentRomStart[]; extern u8 _object_bombiwaSegmentRomEnd[];
extern u8 _object_hintnutsSegmentRomStart[]; extern u8 _object_hintnutsSegmentRomEnd[];
extern u8 _object_rsSegmentRomStart[]; extern u8 _object_rsSegmentRomEnd[];
extern u8 _object_spot00_breakSegmentRomStart[]; extern u8 _object_spot00_breakSegmentRomEnd[];
extern u8 _object_glaSegmentRomStart[]; extern u8 _object_glaSegmentRomEnd[];
extern u8 _object_shopnutsSegmentRomStart[]; extern u8 _object_shopnutsSegmentRomEnd[];
extern u8 _object_geldbSegmentRomStart[]; extern u8 _object_geldbSegmentRomEnd[];
extern u8 _object_grSegmentRomStart[]; extern u8 _object_grSegmentRomEnd[];
extern u8 _object_dogSegmentRomStart[]; extern u8 _object_dogSegmentRomEnd[];
extern u8 _object_jya_ironSegmentRomStart[]; extern u8 _object_jya_ironSegmentRomEnd[];
extern u8 _object_jya_doorSegmentRomStart[]; extern u8 _object_jya_doorSegmentRomEnd[];
extern u8 _object_spot11_objSegmentRomStart[]; extern u8 _object_spot11_objSegmentRomEnd[];
extern u8 _object_kibako2SegmentRomStart[]; extern u8 _object_kibako2SegmentRomEnd[];
extern u8 _object_dnsSegmentRomStart[]; extern u8 _object_dnsSegmentRomEnd[];
extern u8 _object_dnkSegmentRomStart[]; extern u8 _object_dnkSegmentRomEnd[];
extern u8 _object_gi_fireSegmentRomStart[]; extern u8 _object_gi_fireSegmentRomEnd[];
extern u8 _object_gi_insectSegmentRomStart[]; extern u8 _object_gi_insectSegmentRomEnd[];
extern u8 _object_gi_butterflySegmentRomStart[]; extern u8 _object_gi_butterflySegmentRomEnd[];
extern u8 _object_gi_ghostSegmentRomStart[]; extern u8 _object_gi_ghostSegmentRomEnd[];
extern u8 _object_gi_soulSegmentRomStart[]; extern u8 _object_gi_soulSegmentRomEnd[];
extern u8 _object_bowlSegmentRomStart[]; extern u8 _object_bowlSegmentRomEnd[];
extern u8 _object_demo_kekkaiSegmentRomStart[]; extern u8 _object_demo_kekkaiSegmentRomEnd[];
extern u8 _object_efc_doughnutSegmentRomStart[]; extern u8 _object_efc_doughnutSegmentRomEnd[];
extern u8 _object_gi_dekupouchSegmentRomStart[]; extern u8 _object_gi_dekupouchSegmentRomEnd[];
extern u8 _object_ganon_anime1SegmentRomStart[]; extern u8 _object_ganon_anime1SegmentRomEnd[];
extern u8 _object_ganon_anime2SegmentRomStart[]; extern u8 _object_ganon_anime2SegmentRomEnd[];
extern u8 _object_ganon_anime3SegmentRomStart[]; extern u8 _object_ganon_anime3SegmentRomEnd[];
extern u8 _object_gi_rupySegmentRomStart[]; extern u8 _object_gi_rupySegmentRomEnd[];
extern u8 _object_spot01_matoyaSegmentRomStart[]; extern u8 _object_spot01_matoyaSegmentRomEnd[];
extern u8 _object_spot01_matoyabSegmentRomStart[]; extern u8 _object_spot01_matoyabSegmentRomEnd[];
extern u8 _object_muSegmentRomStart[]; extern u8 _object_muSegmentRomEnd[];
extern u8 _object_wfSegmentRomStart[]; extern u8 _object_wfSegmentRomEnd[];
extern u8 _object_skbSegmentRomStart[]; extern u8 _object_skbSegmentRomEnd[];
extern u8 _object_gjSegmentRomStart[]; extern u8 _object_gjSegmentRomEnd[];
extern u8 _object_geffSegmentRomStart[]; extern u8 _object_geffSegmentRomEnd[];
extern u8 _object_haka_doorSegmentRomStart[]; extern u8 _object_haka_doorSegmentRomEnd[];
extern u8 _object_gsSegmentRomStart[]; extern u8 _object_gsSegmentRomEnd[];
extern u8 _object_psSegmentRomStart[]; extern u8 _object_psSegmentRomEnd[];
extern u8 _object_bwallSegmentRomStart[]; extern u8 _object_bwallSegmentRomEnd[];
extern u8 _object_cowSegmentRomStart[]; extern u8 _object_cowSegmentRomEnd[];
extern u8 _object_cobSegmentRomStart[]; extern u8 _object_cobSegmentRomEnd[];
extern u8 _object_gi_sword_1SegmentRomStart[]; extern u8 _object_gi_sword_1SegmentRomEnd[];
extern u8 _object_door_killerSegmentRomStart[]; extern u8 _object_door_killerSegmentRomEnd[];
extern u8 _object_ouke_hakaSegmentRomStart[]; extern u8 _object_ouke_hakaSegmentRomEnd[];
extern u8 _object_timeblockSegmentRomStart[]; extern u8 _object_timeblockSegmentRomEnd[];
extern u8 _object_zl4SegmentRomStart[]; extern u8 _object_zl4SegmentRomEnd[];
extern u8 _g_pn_01SegmentRomStart[]; extern u8 _g_pn_01SegmentRomEnd[];
extern u8 _g_pn_02SegmentRomStart[]; extern u8 _g_pn_02SegmentRomEnd[];
extern u8 _g_pn_03SegmentRomStart[]; extern u8 _g_pn_03SegmentRomEnd[];
extern u8 _g_pn_04SegmentRomStart[]; extern u8 _g_pn_04SegmentRomEnd[];
extern u8 _g_pn_05SegmentRomStart[]; extern u8 _g_pn_05SegmentRomEnd[];
extern u8 _g_pn_06SegmentRomStart[]; extern u8 _g_pn_06SegmentRomEnd[];
extern u8 _g_pn_07SegmentRomStart[]; extern u8 _g_pn_07SegmentRomEnd[];
extern u8 _g_pn_08SegmentRomStart[]; extern u8 _g_pn_08SegmentRomEnd[];
extern u8 _g_pn_09SegmentRomStart[]; extern u8 _g_pn_09SegmentRomEnd[];
extern u8 _g_pn_10SegmentRomStart[]; extern u8 _g_pn_10SegmentRomEnd[];
extern u8 _g_pn_11SegmentRomStart[]; extern u8 _g_pn_11SegmentRomEnd[];
extern u8 _g_pn_12SegmentRomStart[]; extern u8 _g_pn_12SegmentRomEnd[];
extern u8 _g_pn_13SegmentRomStart[]; extern u8 _g_pn_13SegmentRomEnd[];
extern u8 _g_pn_14SegmentRomStart[]; extern u8 _g_pn_14SegmentRomEnd[];
extern u8 _g_pn_15SegmentRomStart[]; extern u8 _g_pn_15SegmentRomEnd[];
extern u8 _g_pn_16SegmentRomStart[]; extern u8 _g_pn_16SegmentRomEnd[];
extern u8 _g_pn_17SegmentRomStart[]; extern u8 _g_pn_17SegmentRomEnd[];
extern u8 _g_pn_18SegmentRomStart[]; extern u8 _g_pn_18SegmentRomEnd[];
extern u8 _g_pn_19SegmentRomStart[]; extern u8 _g_pn_19SegmentRomEnd[];
extern u8 _g_pn_20SegmentRomStart[]; extern u8 _g_pn_20SegmentRomEnd[];
extern u8 _g_pn_21SegmentRomStart[]; extern u8 _g_pn_21SegmentRomEnd[];
extern u8 _g_pn_22SegmentRomStart[]; extern u8 _g_pn_22SegmentRomEnd[];
extern u8 _g_pn_23SegmentRomStart[]; extern u8 _g_pn_23SegmentRomEnd[];
extern u8 _g_pn_24SegmentRomStart[]; extern u8 _g_pn_24SegmentRomEnd[];
extern u8 _g_pn_25SegmentRomStart[]; extern u8 _g_pn_25SegmentRomEnd[];
extern u8 _g_pn_26SegmentRomStart[]; extern u8 _g_pn_26SegmentRomEnd[];
extern u8 _g_pn_27SegmentRomStart[]; extern u8 _g_pn_27SegmentRomEnd[];
extern u8 _g_pn_28SegmentRomStart[]; extern u8 _g_pn_28SegmentRomEnd[];
extern u8 _g_pn_29SegmentRomStart[]; extern u8 _g_pn_29SegmentRomEnd[];
extern u8 _g_pn_30SegmentRomStart[]; extern u8 _g_pn_30SegmentRomEnd[];
extern u8 _g_pn_31SegmentRomStart[]; extern u8 _g_pn_31SegmentRomEnd[];
extern u8 _g_pn_32SegmentRomStart[]; extern u8 _g_pn_32SegmentRomEnd[];
extern u8 _g_pn_33SegmentRomStart[]; extern u8 _g_pn_33SegmentRomEnd[];
extern u8 _g_pn_34SegmentRomStart[]; extern u8 _g_pn_34SegmentRomEnd[];
extern u8 _g_pn_35SegmentRomStart[]; extern u8 _g_pn_35SegmentRomEnd[];
extern u8 _g_pn_36SegmentRomStart[]; extern u8 _g_pn_36SegmentRomEnd[];
extern u8 _g_pn_37SegmentRomStart[]; extern u8 _g_pn_37SegmentRomEnd[];
extern u8 _g_pn_38SegmentRomStart[]; extern u8 _g_pn_38SegmentRomEnd[];
extern u8 _g_pn_39SegmentRomStart[]; extern u8 _g_pn_39SegmentRomEnd[];
extern u8 _g_pn_40SegmentRomStart[]; extern u8 _g_pn_40SegmentRomEnd[];
extern u8 _g_pn_41SegmentRomStart[]; extern u8 _g_pn_41SegmentRomEnd[];
extern u8 _g_pn_42SegmentRomStart[]; extern u8 _g_pn_42SegmentRomEnd[];
extern u8 _g_pn_43SegmentRomStart[]; extern u8 _g_pn_43SegmentRomEnd[];
extern u8 _g_pn_44SegmentRomStart[]; extern u8 _g_pn_44SegmentRomEnd[];
extern u8 _g_pn_45SegmentRomStart[]; extern u8 _g_pn_45SegmentRomEnd[];
extern u8 _g_pn_46SegmentRomStart[]; extern u8 _g_pn_46SegmentRomEnd[];
extern u8 _g_pn_47SegmentRomStart[]; extern u8 _g_pn_47SegmentRomEnd[];
extern u8 _g_pn_48SegmentRomStart[]; extern u8 _g_pn_48SegmentRomEnd[];
extern u8 _g_pn_49SegmentRomStart[]; extern u8 _g_pn_49SegmentRomEnd[];
extern u8 _g_pn_50SegmentRomStart[]; extern u8 _g_pn_50SegmentRomEnd[];
extern u8 _g_pn_51SegmentRomStart[]; extern u8 _g_pn_51SegmentRomEnd[];
extern u8 _g_pn_52SegmentRomStart[]; extern u8 _g_pn_52SegmentRomEnd[];
extern u8 _g_pn_53SegmentRomStart[]; extern u8 _g_pn_53SegmentRomEnd[];
extern u8 _g_pn_54SegmentRomStart[]; extern u8 _g_pn_54SegmentRomEnd[];
extern u8 _g_pn_55SegmentRomStart[]; extern u8 _g_pn_55SegmentRomEnd[];
extern u8 _g_pn_56SegmentRomStart[]; extern u8 _g_pn_56SegmentRomEnd[];
extern u8 _g_pn_57SegmentRomStart[]; extern u8 _g_pn_57SegmentRomEnd[];
extern u8 _nintendo_rogo_staticSegmentRomStart[]; extern u8 _nintendo_rogo_staticSegmentRomEnd[];
extern u8 _title_staticSegmentRomStart[]; extern u8 _title_staticSegmentRomEnd[];
extern u8 _parameter_staticSegmentRomStart[]; extern u8 _parameter_staticSegmentRomEnd[];
extern u8 _vr_cloud2_staticSegmentRomStart[]; extern u8 _vr_cloud2_staticSegmentRomEnd[];
extern u8 _vr_cloud2_pal_staticSegmentRomStart[]; extern u8 _vr_cloud2_pal_staticSegmentRomEnd[];
extern u8 _vr_holy0_staticSegmentRomStart[]; extern u8 _vr_holy0_staticSegmentRomEnd[];
extern u8 _vr_holy0_pal_staticSegmentRomStart[]; extern u8 _vr_holy0_pal_staticSegmentRomEnd[];
extern u8 _vr_holy1_staticSegmentRomStart[]; extern u8 _vr_holy1_staticSegmentRomEnd[];
extern u8 _vr_holy1_pal_staticSegmentRomStart[]; extern u8 _vr_holy1_pal_staticSegmentRomEnd[];
extern u8 _vr_MDVR_staticSegmentRomStart[]; extern u8 _vr_MDVR_staticSegmentRomEnd[];
extern u8 _vr_MDVR_pal_staticSegmentRomStart[]; extern u8 _vr_MDVR_pal_staticSegmentRomEnd[];
extern u8 _vr_MNVR_staticSegmentRomStart[]; extern u8 _vr_MNVR_staticSegmentRomEnd[];
extern u8 _vr_MNVR_pal_staticSegmentRomStart[]; extern u8 _vr_MNVR_pal_staticSegmentRomEnd[];
extern u8 _vr_RUVR_staticSegmentRomStart[]; extern u8 _vr_RUVR_staticSegmentRomEnd[];
extern u8 _vr_RUVR_pal_staticSegmentRomStart[]; extern u8 _vr_RUVR_pal_staticSegmentRomEnd[];
extern u8 _vr_LHVR_staticSegmentRomStart[]; extern u8 _vr_LHVR_staticSegmentRomEnd[];
extern u8 _vr_KHVR_staticSegmentRomStart[]; extern u8 _vr_KHVR_staticSegmentRomEnd[];
extern u8 _vr_K3VR_staticSegmentRomStart[]; extern u8 _vr_K3VR_staticSegmentRomEnd[];
extern u8 _vr_K4VR_staticSegmentRomStart[]; extern u8 _vr_K4VR_staticSegmentRomEnd[];
extern u8 _vr_K5VR_staticSegmentRomStart[]; extern u8 _vr_K5VR_staticSegmentRomEnd[];
extern u8 _vr_SP1a_staticSegmentRomStart[]; extern u8 _vr_SP1a_staticSegmentRomEnd[];
extern u8 _vr_MLVR_staticSegmentRomStart[]; extern u8 _vr_MLVR_staticSegmentRomEnd[];
extern u8 _vr_KKRVR_staticSegmentRomStart[]; extern u8 _vr_KKRVR_staticSegmentRomEnd[];
extern u8 _vr_KR3VR_staticSegmentRomStart[]; extern u8 _vr_KR3VR_staticSegmentRomEnd[];
extern u8 _vr_IPVR_staticSegmentRomStart[]; extern u8 _vr_IPVR_staticSegmentRomEnd[];
extern u8 _vr_KSVR_staticSegmentRomStart[]; extern u8 _vr_KSVR_staticSegmentRomEnd[];
extern u8 _vr_GLVR_staticSegmentRomStart[]; extern u8 _vr_GLVR_staticSegmentRomEnd[];
extern u8 _vr_ZRVR_staticSegmentRomStart[]; extern u8 _vr_ZRVR_staticSegmentRomEnd[];
extern u8 _vr_DGVR_staticSegmentRomStart[]; extern u8 _vr_DGVR_staticSegmentRomEnd[];
extern u8 _vr_ALVR_staticSegmentRomStart[]; extern u8 _vr_ALVR_staticSegmentRomEnd[];
extern u8 _vr_NSVR_staticSegmentRomStart[]; extern u8 _vr_NSVR_staticSegmentRomEnd[];
extern u8 _vr_LBVR_staticSegmentRomStart[]; extern u8 _vr_LBVR_staticSegmentRomEnd[];
extern u8 _vr_TTVR_staticSegmentRomStart[]; extern u8 _vr_TTVR_staticSegmentRomEnd[];
extern u8 _vr_FCVR_staticSegmentRomStart[]; extern u8 _vr_FCVR_staticSegmentRomEnd[];
extern u8 _elf_message_fieldSegmentRomStart[]; extern u8 _elf_message_fieldSegmentRomEnd[];
extern u8 _elf_message_ydanSegmentRomStart[]; extern u8 _elf_message_ydanSegmentRomEnd[];
extern u8 _ydan_sceneSegmentRomStart[]; extern u8 _ydan_sceneSegmentRomEnd[];
extern u8 _ddan_sceneSegmentRomStart[]; extern u8 _ddan_sceneSegmentRomEnd[];
extern u8 _bdan_sceneSegmentRomStart[]; extern u8 _bdan_sceneSegmentRomEnd[];
extern u8 _Bmori1_sceneSegmentRomStart[]; extern u8 _Bmori1_sceneSegmentRomEnd[];
extern u8 _HIDAN_sceneSegmentRomStart[]; extern u8 _HIDAN_sceneSegmentRomEnd[];
extern u8 _MIZUsin_sceneSegmentRomStart[]; extern u8 _MIZUsin_sceneSegmentRomEnd[];
extern u8 _jyasinzou_sceneSegmentRomStart[]; extern u8 _jyasinzou_sceneSegmentRomEnd[];
extern u8 _HAKAdan_sceneSegmentRomStart[]; extern u8 _HAKAdan_sceneSegmentRomEnd[];
extern u8 _HAKAdanCH_sceneSegmentRomStart[]; extern u8 _HAKAdanCH_sceneSegmentRomEnd[];
extern u8 _ice_doukutu_sceneSegmentRomStart[]; extern u8 _ice_doukutu_sceneSegmentRomEnd[];
extern u8 _ganon_sceneSegmentRomStart[]; extern u8 _ganon_sceneSegmentRomEnd[];
extern u8 _men_sceneSegmentRomStart[]; extern u8 _men_sceneSegmentRomEnd[];
extern u8 _gerudoway_sceneSegmentRomStart[]; extern u8 _gerudoway_sceneSegmentRomEnd[];
extern u8 _ganontika_sceneSegmentRomStart[]; extern u8 _ganontika_sceneSegmentRomEnd[];
extern u8 _ganon_sonogo_sceneSegmentRomStart[]; extern u8 _ganon_sonogo_sceneSegmentRomEnd[];
extern u8 _ganontikasonogo_sceneSegmentRomStart[]; extern u8 _ganontikasonogo_sceneSegmentRomEnd[];
extern u8 _takaraya_sceneSegmentRomStart[]; extern u8 _takaraya_sceneSegmentRomEnd[];
extern u8 _ydan_boss_sceneSegmentRomStart[]; extern u8 _ydan_boss_sceneSegmentRomEnd[];
extern u8 _ddan_boss_sceneSegmentRomStart[]; extern u8 _ddan_boss_sceneSegmentRomEnd[];
extern u8 _ddan_boss_room_0SegmentRomStart[]; extern u8 _ddan_boss_room_0SegmentRomEnd[];
extern u8 _ddan_boss_room_1SegmentRomStart[]; extern u8 _ddan_boss_room_1SegmentRomEnd[];
extern u8 _bdan_boss_sceneSegmentRomStart[]; extern u8 _bdan_boss_sceneSegmentRomEnd[];
extern u8 _moribossroom_sceneSegmentRomStart[]; extern u8 _moribossroom_sceneSegmentRomEnd[];
extern u8 _FIRE_bs_sceneSegmentRomStart[]; extern u8 _FIRE_bs_sceneSegmentRomEnd[];
extern u8 _MIZUsin_bs_sceneSegmentRomStart[]; extern u8 _MIZUsin_bs_sceneSegmentRomEnd[];
extern u8 _jyasinboss_sceneSegmentRomStart[]; extern u8 _jyasinboss_sceneSegmentRomEnd[];
extern u8 _HAKAdan_bs_sceneSegmentRomStart[]; extern u8 _HAKAdan_bs_sceneSegmentRomEnd[];
extern u8 _ganon_boss_sceneSegmentRomStart[]; extern u8 _ganon_boss_sceneSegmentRomEnd[];
extern u8 _ganon_final_sceneSegmentRomStart[]; extern u8 _ganon_final_sceneSegmentRomEnd[];
extern u8 _entra_sceneSegmentRomStart[]; extern u8 _entra_sceneSegmentRomEnd[];
extern u8 _entra_n_sceneSegmentRomStart[]; extern u8 _entra_n_sceneSegmentRomEnd[];
extern u8 _enrui_sceneSegmentRomStart[]; extern u8 _enrui_sceneSegmentRomEnd[];
extern u8 _market_alley_sceneSegmentRomStart[]; extern u8 _market_alley_sceneSegmentRomEnd[];
extern u8 _market_alley_n_sceneSegmentRomStart[]; extern u8 _market_alley_n_sceneSegmentRomEnd[];
extern u8 _market_day_sceneSegmentRomStart[]; extern u8 _market_day_sceneSegmentRomEnd[];
extern u8 _market_night_sceneSegmentRomStart[]; extern u8 _market_night_sceneSegmentRomEnd[];
extern u8 _market_ruins_sceneSegmentRomStart[]; extern u8 _market_ruins_sceneSegmentRomEnd[];
extern u8 _shrine_sceneSegmentRomStart[]; extern u8 _shrine_sceneSegmentRomEnd[];
extern u8 _shrine_n_sceneSegmentRomStart[]; extern u8 _shrine_n_sceneSegmentRomEnd[];
extern u8 _shrine_r_sceneSegmentRomStart[]; extern u8 _shrine_r_sceneSegmentRomEnd[];
extern u8 _kokiri_home_sceneSegmentRomStart[]; extern u8 _kokiri_home_sceneSegmentRomEnd[];
extern u8 _kokiri_home3_sceneSegmentRomStart[]; extern u8 _kokiri_home3_sceneSegmentRomEnd[];
extern u8 _kokiri_home4_sceneSegmentRomStart[]; extern u8 _kokiri_home4_sceneSegmentRomEnd[];
extern u8 _kokiri_home5_sceneSegmentRomStart[]; extern u8 _kokiri_home5_sceneSegmentRomEnd[];
extern u8 _kakariko_sceneSegmentRomStart[]; extern u8 _kakariko_sceneSegmentRomEnd[];
extern u8 _kakariko3_sceneSegmentRomStart[]; extern u8 _kakariko3_sceneSegmentRomEnd[];
extern u8 _shop1_sceneSegmentRomStart[]; extern u8 _shop1_sceneSegmentRomEnd[];
extern u8 _kokiri_shop_sceneSegmentRomStart[]; extern u8 _kokiri_shop_sceneSegmentRomEnd[];
extern u8 _golon_sceneSegmentRomStart[]; extern u8 _golon_sceneSegmentRomEnd[];
extern u8 _zoora_sceneSegmentRomStart[]; extern u8 _zoora_sceneSegmentRomEnd[];
extern u8 _drag_sceneSegmentRomStart[]; extern u8 _drag_sceneSegmentRomEnd[];
extern u8 _alley_shop_sceneSegmentRomStart[]; extern u8 _alley_shop_sceneSegmentRomEnd[];
extern u8 _night_shop_sceneSegmentRomStart[]; extern u8 _night_shop_sceneSegmentRomEnd[];
extern u8 _face_shop_sceneSegmentRomStart[]; extern u8 _face_shop_sceneSegmentRomEnd[];
extern u8 _link_home_sceneSegmentRomStart[]; extern u8 _link_home_sceneSegmentRomEnd[];
extern u8 _impa_sceneSegmentRomStart[]; extern u8 _impa_sceneSegmentRomEnd[];
extern u8 _malon_stable_sceneSegmentRomStart[]; extern u8 _malon_stable_sceneSegmentRomEnd[];
extern u8 _labo_sceneSegmentRomStart[]; extern u8 _labo_sceneSegmentRomEnd[];
extern u8 _hylia_labo_sceneSegmentRomStart[]; extern u8 _hylia_labo_sceneSegmentRomEnd[];
extern u8 _tent_sceneSegmentRomStart[]; extern u8 _tent_sceneSegmentRomEnd[];
extern u8 _hut_sceneSegmentRomStart[]; extern u8 _hut_sceneSegmentRomEnd[];
extern u8 _daiyousei_izumi_sceneSegmentRomStart[]; extern u8 _daiyousei_izumi_sceneSegmentRomEnd[];
extern u8 _yousei_izumi_tate_sceneSegmentRomStart[]; extern u8 _yousei_izumi_tate_sceneSegmentRomEnd[];
extern u8 _yousei_izumi_yoko_sceneSegmentRomStart[]; extern u8 _yousei_izumi_yoko_sceneSegmentRomEnd[];
extern u8 _kakusiana_sceneSegmentRomStart[]; extern u8 _kakusiana_sceneSegmentRomEnd[];
extern u8 _hakaana_sceneSegmentRomStart[]; extern u8 _hakaana_sceneSegmentRomEnd[];
extern u8 _hakaana2_sceneSegmentRomStart[]; extern u8 _hakaana2_sceneSegmentRomEnd[];
extern u8 _hakaana_ouke_sceneSegmentRomStart[]; extern u8 _hakaana_ouke_sceneSegmentRomEnd[];
extern u8 _syatekijyou_sceneSegmentRomStart[]; extern u8 _syatekijyou_sceneSegmentRomEnd[];
extern u8 _tokinoma_sceneSegmentRomStart[]; extern u8 _tokinoma_sceneSegmentRomEnd[];
extern u8 _kenjyanoma_sceneSegmentRomStart[]; extern u8 _kenjyanoma_sceneSegmentRomEnd[];
extern u8 _hairal_niwa_sceneSegmentRomStart[]; extern u8 _hairal_niwa_sceneSegmentRomEnd[];
extern u8 _hairal_niwa_n_sceneSegmentRomStart[]; extern u8 _hairal_niwa_n_sceneSegmentRomEnd[];
extern u8 _hiral_demo_sceneSegmentRomStart[]; extern u8 _hiral_demo_sceneSegmentRomEnd[];
extern u8 _hakasitarelay_sceneSegmentRomStart[]; extern u8 _hakasitarelay_sceneSegmentRomEnd[];
extern u8 _turibori_sceneSegmentRomStart[]; extern u8 _turibori_sceneSegmentRomEnd[];
extern u8 _nakaniwa_sceneSegmentRomStart[]; extern u8 _nakaniwa_sceneSegmentRomEnd[];
extern u8 _bowling_sceneSegmentRomStart[]; extern u8 _bowling_sceneSegmentRomEnd[];
extern u8 _souko_sceneSegmentRomStart[]; extern u8 _souko_sceneSegmentRomEnd[];
extern u8 _miharigoya_sceneSegmentRomStart[]; extern u8 _miharigoya_sceneSegmentRomEnd[];
extern u8 _miharigoya_room_0SegmentRomStart[]; extern u8 _miharigoya_room_0SegmentRomEnd[];
extern u8 _mahouya_sceneSegmentRomStart[]; extern u8 _mahouya_sceneSegmentRomEnd[];
extern u8 _ganon_demo_sceneSegmentRomStart[]; extern u8 _ganon_demo_sceneSegmentRomEnd[];
extern u8 _kinsuta_sceneSegmentRomStart[]; extern u8 _kinsuta_sceneSegmentRomEnd[];
extern u8 _kinsuta_room_0SegmentRomStart[]; extern u8 _kinsuta_room_0SegmentRomEnd[];
extern u8 _spot00_sceneSegmentRomStart[]; extern u8 _spot00_sceneSegmentRomEnd[];
extern u8 _spot01_sceneSegmentRomStart[]; extern u8 _spot01_sceneSegmentRomEnd[];
extern u8 _spot02_sceneSegmentRomStart[]; extern u8 _spot02_sceneSegmentRomEnd[];
extern u8 _spot03_sceneSegmentRomStart[]; extern u8 _spot03_sceneSegmentRomEnd[];
extern u8 _spot04_sceneSegmentRomStart[]; extern u8 _spot04_sceneSegmentRomEnd[];
extern u8 _spot05_sceneSegmentRomStart[]; extern u8 _spot05_sceneSegmentRomEnd[];
extern u8 _spot06_sceneSegmentRomStart[]; extern u8 _spot06_sceneSegmentRomEnd[];
extern u8 _spot07_sceneSegmentRomStart[]; extern u8 _spot07_sceneSegmentRomEnd[];
extern u8 _spot08_sceneSegmentRomStart[]; extern u8 _spot08_sceneSegmentRomEnd[];
extern u8 _spot09_sceneSegmentRomStart[]; extern u8 _spot09_sceneSegmentRomEnd[];
extern u8 _spot10_sceneSegmentRomStart[]; extern u8 _spot10_sceneSegmentRomEnd[];
extern u8 _spot11_sceneSegmentRomStart[]; extern u8 _spot11_sceneSegmentRomEnd[];
extern u8 _spot12_sceneSegmentRomStart[]; extern u8 _spot12_sceneSegmentRomEnd[];
extern u8 _spot13_sceneSegmentRomStart[]; extern u8 _spot13_sceneSegmentRomEnd[];
extern u8 _spot15_sceneSegmentRomStart[]; extern u8 _spot15_sceneSegmentRomEnd[];
extern u8 _spot16_sceneSegmentRomStart[]; extern u8 _spot16_sceneSegmentRomEnd[];
extern u8 _spot17_sceneSegmentRomStart[]; extern u8 _spot17_sceneSegmentRomEnd[];
extern u8 _spot18_sceneSegmentRomStart[]; extern u8 _spot18_sceneSegmentRomEnd[];
extern u8 _spot20_sceneSegmentRomStart[]; extern u8 _spot20_sceneSegmentRomEnd[];
extern u8 _ganon_tou_sceneSegmentRomStart[]; extern u8 _ganon_tou_sceneSegmentRomEnd[];
extern u8 _test01_sceneSegmentRomStart[]; extern u8 _test01_sceneSegmentRomEnd[];
extern u8 _test01_room_0SegmentRomStart[]; extern u8 _test01_room_0SegmentRomEnd[];
extern u8 _besitu_sceneSegmentRomStart[]; extern u8 _besitu_sceneSegmentRomEnd[];
extern u8 _depth_test_sceneSegmentRomStart[]; extern u8 _depth_test_sceneSegmentRomEnd[];
extern u8 _syotes_sceneSegmentRomStart[]; extern u8 _syotes_sceneSegmentRomEnd[];
extern u8 _syotes2_sceneSegmentRomStart[]; extern u8 _syotes2_sceneSegmentRomEnd[];
extern u8 _sutaru_sceneSegmentRomStart[]; extern u8 _sutaru_sceneSegmentRomEnd[];
extern u8 _sutaru_room_0SegmentRomStart[]; extern u8 _sutaru_room_0SegmentRomEnd[];
extern u8 _hairal_niwa2_sceneSegmentRomStart[]; extern u8 _hairal_niwa2_sceneSegmentRomEnd[];
extern u8 _sasatest_sceneSegmentRomStart[]; extern u8 _sasatest_sceneSegmentRomEnd[];
extern u8 _testroom_sceneSegmentRomStart[]; extern u8 _testroom_sceneSegmentRomEnd[];
extern u8 _testroom_room_0SegmentRomStart[]; extern u8 _testroom_room_0SegmentRomEnd[];
extern u8 _testroom_room_1SegmentRomStart[]; extern u8 _testroom_room_1SegmentRomEnd[];
extern u8 _testroom_room_2SegmentRomStart[]; extern u8 _testroom_room_2SegmentRomEnd[];
extern u8 _testroom_room_3SegmentRomStart[]; extern u8 _testroom_room_3SegmentRomEnd[];
extern u8 _testroom_room_4SegmentRomStart[]; extern u8 _testroom_room_4SegmentRomEnd[];
extern u8 D_00113070[];
extern u8 D_001579A0[];
extern u8 D_02000000[];
extern u8 D_02000400[];
extern u8 D_02000500[];
extern u8 D_02000900[];
extern u8 D_02000A00[][0x400];
extern u8 D_02001E00[];
extern u8 D_02001F00[];
extern u8 D_02002FC0[];
extern u8 D_02002000[];
extern u8 D_02002100[];
extern u8 D_02002500[];
extern u8 D_02002580[];
extern u8 D_02002600[];
extern u8 D_02002900[];
extern u8 D_02003040[][0x80];
extern u8 D_020035C0[][0x40];
extern u8 D_020038C0[];
extern u8 D_02003940[];
extern u8 D_02003AC0[];
extern u32 D_0201DA50;
extern u32 D_0300AA48;
extern u32 D_03012B20;
extern u32 D_04004298;
extern u32 D_0400CB70;
extern u32 D_04010130;
extern u32 D_0401E370;
extern u32 D_0403B030;
extern u32 D_0403BBA0;
extern u32 D_0403BCD8;
extern u32 D_0403F070;
extern u32 D_04042440;
extern u32 D_04048180;
extern Gfx D_04049210[];
extern u32 D_04049AD0;
extern u32 D_0404D450;
extern u8 D_080895C0[];
extern u32 osTvType;
extern u32 osRomBase;
extern u32 osResetType;
extern u32 osMemSize;
extern u8 osAppNmiBuffer[];
extern u8 D_80009320[];
extern u8 D_800093F0[];
extern u8 D_80009430;
extern volatile u8 gViConfigUseDefault;
extern u8 gViConfigAdditionalScanLines;
extern u32 gViConfigFeatures;
extern f32 gViConfigXScale;
extern f32 gViConfigYScale;
extern OSPiHandle* gCartHandle;
extern u32 gCurrentRegion;
extern u32 __osPiAccessQueueEnabled;
extern OSViMode osViModePalLan1;
extern u64 osClockRate;
extern u32 osViClock;
extern u32 __osShutdown;
extern u32 __OSGlobalIntMask;
extern __osHwInt __osHwIntTable[];
extern OSThread* __osThreadTail[];
extern OSThread *__osRunQueue;
extern OSThread *__osActiveQueue;
extern OSThread *__osRunningThread;
extern OSThread* __osFaultedThread;
extern OSMgrArgs __osPiDevMgr;
extern OSPiHandle* __osPiTable;
extern OSPiHandle* __osCurrentHandle[];
extern OSTimer* __osTimerList;
extern OSViMode osViModeNtscLan1;
extern OSViMode osViModeMpalLan1;
extern OSViContext* __osViCurr;
extern OSViContext* __osViNext;
extern OSViMode osViModeFpalLan1;
extern u32 __additional_scanline;
extern u8 gBuildTeam[];
extern u8 gBuildDate[];
extern u8 gBuildMakeOption[];
extern OSMesgQueue gPiMgrCmdQ;
extern OSViMode gViConfigMode;
extern u8 D_80013960;
extern OSMesg piAccessBuf;
extern OSMesgQueue __osPiAccessQueue;
extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;
extern OSThread __osThreadSave;
extern __OSEventState __osEventStateTab[];
extern OSTimer __osBaseTimer;
extern OSTime __osCurrentTime;
extern u32 __osBaseCounter;
extern u32 __osViIntrCount;
extern u32 __osTimerCounter;
extern OSPiHandle __CartRomHandle;
extern DmaEntry gDmaDataTable[0x60C];
extern u8 D_801120C0[];
extern EffectTableInfo EffectSS2Info;
extern Gfx D_80116280[];
extern ActorOverlay gActorOverlayTable[471];
extern s32 gMaxProfile;
extern s32 D_8011D394;
extern s32 D_8011D3AC;
extern s16 D_8011E0B0;
extern Color_RGBA8 D_8011E0B4[];
extern GameStateOverlay gGameStateOverlayTable[6];
extern u8 D_8011FB30;
extern u8 D_8011FB38;
extern u16 D_8011FB40;
extern s32 gZeldaArenaLogSeverity;
extern s16 D_80120130;
extern s16 gSpoilingItems[3];
extern s16 gSpoilingItemReverts[3];
extern Gfx gEmptyDL[];
extern u32 gBitFlags[32];
extern u16 gEquipMasks[4];
extern u16 gEquipNegMasks[4];
extern u32 gUpgradeMasks[8];
extern u32 gUpgradeNegMasks[8];
extern u8 gEquipShifts[4];
extern u8 gUpgradeShifts[8];
extern u16 gUpgradeCapacities[8][4];
extern u32 gItemIcons[0x82];
extern u8 gItemSlots[56];
extern void (*gSceneCmdHandlers[26])(GlobalContext*, SceneCmd*);
extern s16 gLinkObjectIds[2];
extern u32 gObjectTableSize;
extern RomFile gObjectTable[402];
extern EntranceInfo gEntranceTable[1556];
extern Scene gSceneTable[110];
extern u8 gLetterTLUT[4][32];
extern u8 gFontFF[];
extern KaleidoManagerOvl gKaleidoMgrOverlayTable[2];
extern KaleidoManagerOvl* gKaleidoMgrCurOvl;
extern void* D_8012D1F0;
extern u32 gScreenWidth;
extern u32 gScreenHeight;
extern u32 gSystemHeapSize;
extern volatile u32 D_8012D290;
extern Mtx gMtxClear;
extern MtxF gMtxFClear;
extern u32 D_8012DBC0;
extern volatile u32 gIrqMgrResetStatus;
extern u32 D_8012DBA0;
extern u32 D_8012DBA4;
extern s32 gDebugArenaLogSeverity;
extern Vec3f D_801333D4;
extern u32 D_801333E0;
extern u32 D_801333E8;
extern s32 gOverlayLogSeverity;
extern s32 gSystemArenaLogSeverity;
extern char D_80135180[];
extern char D_80135194[];
extern char D_801357DC[];
extern char D_80136208[];
extern char D_80136218[];
extern char D_80136228[];
extern char D_80136238[];
extern char D_80136A54[];
extern char D_80136A68[];
extern char D_80136A7C[];
extern char D_80136A90[];
extern char D_80136AA4[];
extern char D_80136AB8[];
extern f32 D_80136D3C;
extern f32 D_80136D40;
extern f32 D_80136D44;
extern char D_8013C190[];
extern char D_8013C860[];
extern char D_8013C874[];
extern f32 D_8013C888;
extern f32 D_8013C88C;
extern f32 D_8013C890;
extern f32 D_8013C894;
extern f32 D_8013C898;
extern f32 D_8013CB80;
extern u32* D_8013E960;
extern u32* D_8013E99C;
extern char D_80141030[];
extern char D_80145F68[];
extern char D_80145F94[];
extern char D_80145FA0[];
extern char D_80145FFC[];
extern char D_80146014[];
extern char D_801461CC[];
extern char D_80146230[];
extern char D_80146238[];
extern u8 D_80155F50[];
extern GlobalContext* D_80157DA0;
extern SaveContext gSaveContext;
extern u32 D_8015FA88;
extern u32 D_8015FA8C;
extern GameInfo* gGameInfo;
extern u8 D_8015FCF0;
extern Vec3f D_8015FCF8;
extern s16 D_8015FD04;
extern s16 D_8015FD06;
extern f32 D_8015FD08;
extern s16 D_8015FD0C;
extern u8 D_8015FD70;
extern u8 D_80161010;
extern u8 D_801610D4;
extern u8 D_801610D5;
extern u8 D_801610DA;
extern s32 D_80161490;
extern Color_RGBA8 D_801614B0;
extern PreNmiBuff* gAppNmiBufferPtr;
extern u8 D_80166B68;
extern u32 gSegments[];
extern volatile OSTime D_8016A520;
extern volatile OSTime D_8016A528;
extern volatile OSTime D_8016A530;
extern volatile OSTime D_8016A538;
extern volatile OSTime D_8016A540;
extern volatile OSTime D_8016A548;
extern volatile OSTime D_8016A550;
extern volatile OSTime D_8016A558;
extern volatile OSTime D_8016A560;
extern volatile OSTime D_8016A568;
extern volatile OSTime D_8016A580;
extern FaultThreadStruct* sFaultStructPtr;
extern u8 sFaultIsWaitingForInput;
extern char sFaultStack[0x600];
extern char sFaultThreadInfo[0x20];
extern FaultThreadStruct gFaultStruct;
extern u32 D_8016B5F5;
extern u32 __osMalloc_FreeBlockTest_Enable;
extern Arena gSystemArena;
extern u8 D_801759C0[];
extern u16 gZBuffer[320 * 240];
extern u64 gGfxSPTaskOutputBuffer[0x3000];
extern u8 gGfxSPTaskYieldBuffer[0xC00];
extern u8 gGfxSPTaskStack[0x400];
extern GfxPool gGfxPools[2];
extern u8 gAudioHeap[0x38000];
extern u8 gSystemHeap[];
extern MapMarksData* gMapMarkDataTable[];
typedef struct {
                 Actor actor;
                 SkelAnime skelAnime;
                 Vec3s unk_190;
                 char unk_196[0x72];
                 Vec3s unk_208;
                 char unk_20E[0x72];
                 ActorFunc actionFunc;
                 char unk_284[0x22];
                 s16 unk_2A6;
                 char unk_2A8[0xA4];
                 ColliderCylinderMain collider;
} EnDivingGame;
extern const ActorInit En_Diving_Game_InitVars;
void EnDivingGame_Init(EnDivingGame* this, GlobalContext* globalCtx);
void EnDivingGame_Destroy(EnDivingGame* this, GlobalContext* globalCtx);
void EnDivingGame_Update(EnDivingGame* this, GlobalContext* globalCtx);
void EnDivingGame_Draw(EnDivingGame* this, GlobalContext* globalCtx);
void func_809EDCB0(EnDivingGame* this, GlobalContext* globalCtx);
void func_809ED9E0(EnDivingGame* this, GlobalContext* globalCtx);
extern Gfx* D_0600BFA8;
extern Gfx* D_06002FE8;
extern ColliderCylinderInit D_809EF0B4;
extern u8 D_809EF0B0;
void EnDivingGame_Init(EnDivingGame *this, GlobalContext *globalCtx) {
    Actor* thisx = &this->actor;
    thisx->gravity = -3.0f;
    ActorShape_Init(&thisx->shape, 0, ActorShadow_DrawFunc_Circle, 30.0f);
    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_0600BFA8, &D_06002FE8, &this->unk_190, &this->unk_208, 0x14);
    ActorCollider_AllocCylinder(globalCtx, &this->collider);
    ActorCollider_InitCylinder(globalCtx, &this->collider, this, &D_809EF0B4);
    osSyncPrintf("\x1b" "[" "3" "2" "m" "☆☆☆☆☆ 素もぐりＧＯ ☆☆☆☆☆ \n" "\x1b" "[" "" "m");
    thisx->room = -1;
    thisx->scale.x = 0.01f;
    thisx->scale.y = 1.2999999e-2;
    thisx->scale.z = 1.39999995008111e-2;
    if (D_809EF0B0 != 0) {
        osSyncPrintf("\x1b" "[" "3" "2" "m" "☆☆☆☆☆ もういてる原 ☆☆☆☆☆ \n" "\x1b" "[" "" "m");
        this->unk_284[0x9B] = 1;
        Actor_Kill(thisx);
    }
    else
    {
    D_809EF0B0 = (u8)1U;
    this->actor.unk_1F = (u8)0;
    this->actor.sub_98.mass = (u8)0xFFU;
    this->actionFunc = func_809EDCB0;
    }
}
void EnDivingGame_Destroy(EnDivingGame* this,GlobalContext* globalCtx)
{
  if (this->unk_284[0x9b] == '\0')
  {
    gSaveContext.timer_1_state = 0;
  }
  ActorCollider_FreeCylinder(globalCtx, &this->collider);
}
void func_809ED9E0(EnDivingGame *this, GlobalContext *globalCtx) {
    Actor* unkActor;
    Vec3f sp40;
    Actor* thisx = &this->actor;
    sp40.x = ((Math_Rand_ZeroOne() - 0.5f) * 30.0f) + thisx->posRot.pos.x;
    sp40.y = ((Math_Rand_ZeroOne() - 0.5f) * 20.0f) + (thisx->posRot.pos.y + 30.0f);
    sp40.z = ((Math_Rand_ZeroOne() - 0.5f) * 20.0f) + thisx->posRot.pos.z;
    unkActor = Actor_SpawnAttached(&globalCtx->actorCtx, thisx, globalCtx, 0x131,
    sp40.x, sp40.y, sp40.z, 0, ((((s16)Math_Rand_CenteredFloat(3500.0f))) - 0x3E8), this->unk_2A6, 0);
    if (unkActor != ((void*)0)) {
        unkActor->speedXZ = 12.0f;
        unkActor->velocity.y = 6.0f;
    }
}
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EDB08.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EDCB0.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EDD4C.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EDEDC.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE048.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE0FC.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE194.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE1F4.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE408.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE6C8.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE780.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE800.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE8F0.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EE96C.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EEA00.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EEA90.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EEAF8.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/EnDivingGame_Update.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EEDB8.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/func_809EEDE4.s")
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Diving_Game/EnDivingGame_Draw.s")
