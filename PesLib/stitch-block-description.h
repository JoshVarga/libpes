#ifndef STITCHBLOCKDESCRIPTION_H
#define STITCHBLOCKDESCRIPTION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "affine-transform.h"
#include "block-geometry.h"
#include "pes-motif.h"

struct stitch_block_description
{
    struct block_geometry *geometry;

    short IsOpenPath; /* bool */
    short UseOutline; /* bool */
    short OutlineStitchType; // 0 = Zigzag, 1 = run Stitch
    short outline_color_index;
    short ZigzagWidth;
    short ZigzagDensity;
    short OutlineRunPitch;
    short RunStitchRunTimes;
    short triple_stitch_run_pitch;
    short OutlineUseHalfStitch; /* bool */
    short UseOutlineUnderSewing;
    short UseSharpCorners;
    struct motif_stitch *MotifLine;

    short EStitchOrVStitch;
    short EvStitchTallWidth;
    short EvStitchHeight;
    short EvStitchPointWidth;
    short EvStitchRunTimes;
    short EvStitchStrokeTimes;
    short EvStitchArrange;

    short UseFill; /* bool */
    short FillType;
    short RegionDensity;

    short UseGradation; /* bool */
    struct short_array *GradationValues;

    short UseAdditionalColorInGradation; /* bool */ 
    short gradation_second_color; // Index into supplied header color table
    short IsStitchDirectionVariable; /* bool */
    short StitchDirection;
    int   fill_color_index; // Index into supplied header color table
    
    short BaseSewingStepPitch;
    short BaseSewingFrequency;
    short BaseSewingStitchType; /* 0 = Square edge, 1 = Zigzag */
    short FillHalfStitch;
    short RunningStitchPath;
    short ProgrammableFillPatternIndex;
    short ProgrammableFillWidth;
    short ProgrammableFillHeight;
    short ProgrammableFillRowOrColumn;
    short ProgrammableFillRowOffset;
    short ProgrammableFillColumnOffset;
    short ProgrammableFillDirection;
    short PullCompensation;

    short UseBaseSewing;

    short useFillAreaUnderSewing;
    short FillAreaUnderSewingType;
    // Motif section

    short UseMotifPattern1; /* bool */
    struct motif *MotifFillPattern1;

    short UseMotifPattern2; /* bool */
    struct motif *MotifFillPattern2;

    short MotifRowOffset;
    short MotifStitchDirection; // in degrees
    short MotifRunPitch; //default: 100

    short pipingStitchDensity;
    short pipingStitchRunPitch;
    short pipingStitchFrequency;
    short pipingStitchDirection;
    // CrossStitch section

    short CrossStitchSizeMeasure;
    short CrossStitchSizeInMM; // default: 25
    short CrossStitchTimes; // default: 2

    short RadialDensity; // default: 20
    short RadialRunPitch; // default: 20
    int RadialCenterX; // 961
    int RadialCenterY; // 847

    short ConcentricCircleDensity; // default: 20
    short ConcentricCircleRunPitch; // default: 20
    int ConcentricCircleCenterX; // 961
    int ConcentricCircleCenterY; // 847

    short SpiralDensity; // default : 20
    short SpiralRunPitch; // default : 20

    short StipplingRunPitch;
    short StipplingSpacing;

    short OutlineEntryv1;
    float OutlineEntry;

    short OutlineExitv1;
    float OutlineExit;

    short RegionEntryv1;
    float RegionEntry;

    short RegionExitv1;
    float RegionExit;
};

struct stitch_block_description *stitch_block_description_read(FILE *file);
void stitch_block_description_write(FILE *file, struct stitch_block_description *block);
void stitch_block_description_print(struct stitch_block_description *block);
void stitch_block_description_free(struct stitch_block_description *block);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* STITCHBLOCKDESCRIPTION_H */



