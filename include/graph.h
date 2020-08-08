#ifndef _GRAPH_H
#define _GRAPH_H

#include "THA_GA.h"

struct GraphicsContext;

typedef union {
    struct {
        short type;
    } gen;
    struct {
        short type;
    } done;
    OSScMsg app;
} GraphMsg;

/*
 * Macro for registering callback function when task ends
 * Note) Only one function can be registered because it is a negligence
 */
#define graph_AddTaskEndCallBack(graph, callback, client_data) \
    do {                                                       \
        (graph)->TaskEndCallBack = (callback);                 \
        (graph)->TaskEndClientData = (client_data);            \
    } while (0)
#define graph_RemoveTaskEndCallBack(graph, callback, client_data)                                    \
    do {                                                                                             \
        if ((graph)->TaskEndCallBack == (callback) && (graph)->TaskEndClientData == (client_data)) { \
            (graph)->TaskEndCallBack = NULL;                                                         \
            (graph)->TaskEndClientData = NULL;                                                       \
        }                                                                                            \
    } while (0)

#ifndef ROM_D
#define OPEN_DISP(graph)           \
    {                              \
        Graph* __graph = (graph);  \
        int __poly_gfx_opened = 0; \
        (void)0 /* rquire `;'  */

#define CLOSE_DISP(graph)                \
    do {                                 \
        (void)&(graph)->Gfx_list00P_top; \
        (void)__poly_gfx_opened;         \
    } while (0);                         \
    }                                    \
    (void)0 /* rquire `;'  */
#else
typedef struct {
    Gfx* tmp_poly_opa;
    Gfx* tmp_poly_xlu;
    Gfx* tmp_overlay;
} __GraphCheck;
extern void Graph_OpenDisps(__GraphCheck* this, struct GraphicsContext* graph, char* file, s32 line);
extern void Graph_CloseDisps(__GraphCheck* this, struct GraphicsContext* graph, char* file, s32 line);
#define OPEN_DISP(graph, file, line)                        \
{                                               \
    GraphicsContext *__graph = (graph);                   \
    int __poly_gfx_opened = 0;                  \
    __GraphCheck __graphcheck;                  \
    Graph_OpenDisps(&__graphcheck, graph, file, line); \
    (void)0                     /* rquire `;'  */

#define CLOSE_DISP(graph, file, line)                       \
    do {                                        \
        Graph_CloseDisps(&__graphcheck, graph, file, line); \
        (void)__poly_gfx_opened;                \
    } while (0);                                \
}   (void)0                     /* rquire `;'  */
#endif

#define NEXT_POLY_OPA_DISP              THA_GA_NEXT_DISP(&__graph->polyOpa)
#define NEXT_POLY_XLU_DISP              THA_GA_NEXT_DISP(&__graph->polyXlu)
#ifndef NOUSE_LINE_UCODE
    #define NEXT_LINE_OPA_DISP          THA_GA_NEXT_DISP(&__graph->lineOpa)
    #define NEXT_LINE_XLU_DISP          THA_GA_NEXT_DISP(&__graph->lineXlu)
#endif /* NOUSE_LINE_UCODE */
#define NEXT_OVERLAY_DISP               THA_GA_NEXT_DISP(&__graph->overlay)
#define NEXT_WORK_DISP                  THA_GA_NEXT_DISP(&__graph->work)
#define NEXT_DISP                       NEXT_POLY_OPA_DISP
#define NOW_POLY_OPA_DISP               (Gfx *)THA_GA_getHeadPtr(&__graph->polyOpa)
#define NOW_POLY_XLU_DISP               (Gfx *)THA_GA_getHeadPtr(&__graph->polyXlu)
#ifndef NOUSE_LINE_UCODE
    #define NOW_LINE_OPA_DISP           (Gfx *)THA_GA_getHeadPtr(&__graph->lineOpa)
    #define NOW_LINE_XLU_DISP           (Gfx *)THA_GA_getHeadPtr(&__graph->lineXlu)
#endif /* NOUSE_LINE_UCODE */

#define NOW_OVERLAY_DISP                (Gfx *)THA_GA_getHeadPtr(&__graph->overlay)
#define NOW_WORK_DISP                   (Gfx *)THA_GA_getHeadPtr(&__graph->work)
#define NOW_DISP                        NOW_POLY_OPA_DISP
#define SET_NOW_POLY_OPA_DISP(ptr)      THA_GA_setHeadPtr(&__graph->polyOpa, ptr)   
#define SET_NOW_POLY_XLU_DISP(ptr)      THA_GA_setHeadPtr(&__graph->polyXlu, ptr)
#ifndef NOUSE_LINE_UCODE
    #define SET_NOW_LINE_OPA_DISP(ptr)  THA_GA_setHeadPtr(&__graph->lineOpa, ptr)
    #define SET_NOW_LINE_XLU_DISP(ptr)  THA_GA_setHeadPtr(&__graph->polyXlu, ptr)
#endif /* NOUSE_LINE_UCODE */

#define SET_NOW_OVERLAY_DISP(ptr)       THA_GA_setHeadPtr(&__graph->overlay, ptr)
#define SET_NOW_WORK_DISP(ptr)          THA_GA_setHeadPtr(&__graph->work, ptr)
#define SET_NOW_DISP(ptr)               SET_NOW_POLY_OPA_DISP(ptr)

#endif
