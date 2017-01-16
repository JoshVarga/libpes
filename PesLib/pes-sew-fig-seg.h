#ifndef CSEWFIGSEG_H
#define CSEWFIGSEG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pes-motif.h"
#include "pes-point.h"

struct pes_sew_fig_seg
{
    short colorIndex;
    short unknown;
    short sideOneStitches;
    struct pes_point **pointsSide1;
    short sideTwoStitches;
    struct pes_point **pointsSide2;
    short RunPitch;

    short FillType;
    short RegionDensity;

    short something2;
    
    float BaseSewingStepPitch;
    short BaseSewingFrequency;
    short BaseSewingStitchType; /* 0 = Square edge, 1 = Zigzag */
    short FillHalfStitch;
    short useFillAreaUnderSewing;
    short FillAreaUnderSewingType;
    short RunningStitchPath;

    short ProgrammableFillPatternIndex;
    short ProgrammableFillWidth;
    short ProgrammableFillHeight;
    short ProgrammableFillRowOrColumn;
    short ProgrammableFillRowOffset;
    short ProgrammableFillColumnOffset;
    short ProgrammableFillDirection;


    short UseBaseSewing;
    short PullCompensation;
    
    short UseMotifPattern1;
    struct motif *MotifFillPattern1;
    short UseMotifPattern2;
    struct motif *MotifFillPattern2;
    
    short MotifRowOffset;
    short MotifRunPitch;

    short IsTopFeathered;
    short IsBottomFeathered;
    short FeatherTopLength;
    short FeatherBottomLength;
    short PipingDensity;
    short PipingRunPitch;
    short PipingFrequency;
    short numberOfStamps; 


    short OutlineEntryv1;
    float OutlineEntry;

    short OutlineExitv1;
    float OutlineExit;

    short RegionEntryv1;
    float RegionEntry;

    short RegionExitv1;
    float RegionExit;
};

struct pes_sew_fig_seg *pes_sew_fig_seg_read(FILE *file);
void pes_sew_fig_seg_print(struct pes_sew_fig_seg *item);
void pes_sew_fig_seg_free(struct pes_sew_fig_seg *block);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CSEWFIGSEG_H */

