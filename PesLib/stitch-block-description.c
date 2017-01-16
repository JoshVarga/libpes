#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers-binary.h"
#include "pes-motif.h"
#include "short-array.h"
#include "stitch-block-description.h"

struct stitch_block_description *stitch_block_description_read(FILE *file)
{
    struct stitch_block_description *block = (struct stitch_block_description *)malloc(sizeof(struct stitch_block_description));
    block->geometry = block_geometry_read(file);
    block->IsOpenPath = binaryReadInt16(file);
    block->UseOutline = binaryReadInt16(file);
    block->OutlineStitchType = binaryReadInt16(file); // 0 = Zigzag, 1 = run Stitch
    block->outline_color_index = binaryReadInt16(file);
    block->ZigzagWidth = binaryReadInt16(file);
    block->ZigzagDensity = binaryReadInt16(file);
    block->OutlineRunPitch = binaryReadInt16(file);
    block->RunStitchRunTimes = binaryReadInt16(file);
    block->triple_stitch_run_pitch = binaryReadInt16(file);
    block->OutlineUseHalfStitch = binaryReadInt16(file);
    
    block->UseOutlineUnderSewing = binaryReadInt16(file);
    block->UseSharpCorners = binaryReadInt16(file);

    block->MotifLine = motif_stitch_read(file);
    
    block->EStitchOrVStitch = binaryReadInt16(file);
    block->EvStitchTallWidth = binaryReadInt16(file);
    block->EvStitchHeight = binaryReadInt16(file);
    block->EvStitchPointWidth = binaryReadInt16(file);
    block->EvStitchRunTimes = binaryReadInt16(file);
    block->EvStitchStrokeTimes = binaryReadInt16(file);
    block->EvStitchArrange = binaryReadInt16(file);
    
    block->UseFill = binaryReadInt16(file);
    block->FillType = binaryReadInt16(file);
    block->RegionDensity = binaryReadInt16(file);

    block->UseGradation = binaryReadInt16(file);
    block->GradationValues = short_array_read(file);
    block->UseAdditionalColorInGradation = binaryReadInt16(file); 
    block->gradation_second_color = binaryReadInt16(file);

    block->IsStitchDirectionVariable = binaryReadInt16(file);
    block->StitchDirection = binaryReadInt16(file);
    
    block->fill_color_index = binaryReadInt16(file);
    block->BaseSewingStepPitch = binaryReadInt16(file);
    block->BaseSewingFrequency = binaryReadInt16(file);
    block->BaseSewingStitchType = binaryReadInt16(file);
    block->FillHalfStitch = binaryReadInt16(file);
    block->useFillAreaUnderSewing = binaryReadInt16(file); // Use UseFillUnderSew

    block->FillAreaUnderSewingType = binaryReadInt16(file); // 0 = 1 direction, 1 = both directions
    block->RunningStitchPath = binaryReadInt16(file); // half-stitch?
    
    block->ProgrammableFillPatternIndex = binaryReadInt16(file);  //20
    block->ProgrammableFillWidth = binaryReadInt16(file);
    block->ProgrammableFillHeight = binaryReadInt16(file);
    block->ProgrammableFillRowOrColumn = binaryReadInt16(file);
    block->ProgrammableFillRowOffset = binaryReadInt16(file);
    block->ProgrammableFillColumnOffset = binaryReadInt16(file);
    block->ProgrammableFillDirection = binaryReadInt16(file); // ProgrammableFillDirection , WHERE IS PULL COMP
    // Motif section
    
    block->UseBaseSewing = binaryReadInt16(file);
    block->PullCompensation = binaryReadInt16(file);

    block->UseMotifPattern1 = binaryReadInt16(file); // default: false

    block->MotifFillPattern1 = motif_read(file);
    
    block->UseMotifPattern2 = binaryReadInt16(file); // default: false
    
    block->MotifFillPattern2 = motif_read(file);
    
    block->MotifRowOffset = binaryReadInt16(file);
    block->MotifStitchDirection = binaryReadInt16(file); // in degrees
    block->MotifRunPitch = binaryReadInt16(file); //default: 100
    
    block->pipingStitchDirection = binaryReadInt16(file);
    block->pipingStitchDensity = binaryReadInt16(file);
    block->pipingStitchRunPitch = binaryReadInt16(file);
    block->pipingStitchFrequency = binaryReadInt16(file);

    // CrossStitch section
    
    block->CrossStitchSizeMeasure = binaryReadInt16(file); // 0 for size, 1 for ct
    block->CrossStitchSizeInMM = binaryReadInt16(file); // default: 25
    block->CrossStitchTimes = binaryReadInt16(file); // default: 2
    
    block->RadialDensity = binaryReadInt16(file); // default: 20
    block->RadialRunPitch = binaryReadInt16(file); // default: 20
    block->RadialCenterX = binaryReadInt32(file); // 961
    block->RadialCenterY = binaryReadInt32(file); // 847
    
    block->ConcentricCircleDensity = binaryReadInt16(file); // default: 20
    block->ConcentricCircleRunPitch = binaryReadInt16(file); // default: 20
    block->ConcentricCircleCenterX = binaryReadInt32(file); // 961
    block->ConcentricCircleCenterY = binaryReadInt32(file); // 847
    
    block->SpiralDensity = binaryReadInt16(file); // default : 20
    block->SpiralRunPitch = binaryReadInt16(file); // default : 20
    
    block->StipplingRunPitch = binaryReadInt16(file);
    block->StipplingSpacing = binaryReadInt16(file);

    block->OutlineEntryv1 = binaryReadInt16(file);
    block->OutlineEntry = binaryReadFloat(file);
    
    block->OutlineExitv1 = binaryReadInt16(file);
    block->OutlineExit = binaryReadFloat(file);
    
    block->RegionEntryv1 = binaryReadInt16(file);
    block->RegionEntry = binaryReadFloat(file);
    
    block->RegionExitv1 = binaryReadInt16(file);
    block->RegionExit = binaryReadFloat(file);
    return block;
}

void stitch_block_description_write(FILE *file, struct stitch_block_description *block)
{
    block_geometry_write(file, block->geometry);
    binaryWriteInt16(file, block->IsOpenPath);
    binaryWriteInt16(file, block->UseOutline);
    binaryWriteInt16(file, block->OutlineStitchType); // 0 = Zigzag, 1 = run Stitch
    binaryWriteInt16(file, block->outline_color_index);
    binaryWriteInt16(file, block->ZigzagWidth);
    binaryWriteInt16(file, block->ZigzagDensity);
    binaryWriteInt16(file, block->OutlineRunPitch);
    binaryWriteInt16(file, block->RunStitchRunTimes);
    binaryWriteInt16(file, block->triple_stitch_run_pitch);
    binaryWriteInt16(file, block->OutlineUseHalfStitch);
    
    binaryWriteInt16(file, block->UseOutlineUnderSewing);
    binaryWriteInt16(file, block->UseSharpCorners);

    motif_stitch_write(file, block->MotifLine);
    
    binaryWriteInt16(file, block->EStitchOrVStitch);
    binaryWriteInt16(file, block->EvStitchTallWidth);
    binaryWriteInt16(file, block->EvStitchHeight);
    binaryWriteInt16(file, block->EvStitchPointWidth);
    binaryWriteInt16(file, block->EvStitchRunTimes);
    binaryWriteInt16(file, block->EvStitchStrokeTimes);
    binaryWriteInt16(file, block->EvStitchArrange);
    
    binaryWriteInt16(file, block->UseFill);
    binaryWriteInt16(file, block->FillType);
    binaryWriteInt16(file, block->RegionDensity);

    binaryWriteInt16(file, block->UseGradation);
    short_array_write(file, block->GradationValues);
    binaryWriteInt16(file, block->UseAdditionalColorInGradation); 
    binaryWriteInt16(file, block->gradation_second_color);

    binaryWriteInt16(file, block->IsStitchDirectionVariable);
    binaryWriteInt16(file, block->StitchDirection);
    
    binaryWriteInt16(file, block->fill_color_index);
    binaryWriteInt16(file, block->BaseSewingStepPitch);
    binaryWriteInt16(file, block->BaseSewingFrequency);
    binaryWriteInt16(file, block->BaseSewingStitchType);
    binaryWriteInt16(file, block->FillHalfStitch);
    binaryWriteInt16(file, block->useFillAreaUnderSewing); // Use UseFillUnderSew

    binaryWriteInt16(file, block->FillAreaUnderSewingType); // 0 = 1 direction, 1 = both directions
    binaryWriteInt16(file, block->RunningStitchPath); // half-stitch?
    
    binaryWriteInt16(file, block->ProgrammableFillPatternIndex);  //20
    binaryWriteInt16(file, block->ProgrammableFillWidth);
    binaryWriteInt16(file, block->ProgrammableFillHeight);
    binaryWriteInt16(file, block->ProgrammableFillRowOrColumn);
    binaryWriteInt16(file, block->ProgrammableFillRowOffset);
    binaryWriteInt16(file, block->ProgrammableFillColumnOffset);
    binaryWriteInt16(file, block->ProgrammableFillDirection); // ProgrammableFillDirection , WHERE IS PULL COMP
    // Motif section
    
    binaryWriteInt16(file, block->UseBaseSewing);
    binaryWriteInt16(file, block->PullCompensation);

    binaryWriteInt16(file, block->UseMotifPattern1); // default: false

    motif_write(file, block->MotifFillPattern1);
    
    binaryWriteInt16(file, block->UseMotifPattern2); // default: false
    
    motif_write(file, block->MotifFillPattern2);
    
    binaryWriteInt16(file, block->MotifRowOffset);
    binaryWriteInt16(file, block->MotifStitchDirection); // in degrees
    binaryWriteInt16(file, block->MotifRunPitch); //default: 100
    
    binaryWriteInt16(file, block->pipingStitchDirection);
    binaryWriteInt16(file, block->pipingStitchDensity);
    binaryWriteInt16(file, block->pipingStitchRunPitch);
    binaryWriteInt16(file, block->pipingStitchFrequency);

    // CrossStitch section
    
    binaryWriteInt16(file, block->CrossStitchSizeMeasure); // 0 for size, 1 for ct
    binaryWriteInt16(file, block->CrossStitchSizeInMM); // default: 25
    binaryWriteInt16(file, block->CrossStitchTimes); // default: 2
    
    binaryWriteInt16(file, block->RadialDensity); // default: 20
    binaryWriteInt16(file, block->RadialRunPitch); // default: 20
    binaryWriteInt32(file, block->RadialCenterX); // 961
    binaryWriteInt32(file, block->RadialCenterY); // 847
    
    binaryWriteInt16(file, block->ConcentricCircleDensity); // default: 20
    binaryWriteInt16(file, block->ConcentricCircleRunPitch); // default: 20
    binaryWriteInt32(file, block->ConcentricCircleCenterX); // 961
    binaryWriteInt32(file, block->ConcentricCircleCenterY); // 847
    
    binaryWriteInt16(file, block->SpiralDensity); // default : 20
    binaryWriteInt16(file, block->SpiralRunPitch); // default : 20
    
    binaryWriteInt16(file, block->StipplingRunPitch);
    binaryWriteInt16(file, block->StipplingSpacing);

    binaryWriteInt16(file, block->OutlineEntryv1);
    binaryWriteFloat(file, block->OutlineEntry);
    
    binaryWriteInt16(file, block->OutlineExitv1);
    binaryWriteFloat(file, block->OutlineExit);
    
    binaryWriteInt16(file, block->RegionEntryv1);
    binaryWriteFloat(file, block->RegionEntry);
    
    binaryWriteInt16(file, block->RegionExitv1);
    binaryWriteFloat(file, block->RegionExit);
}

void stitch_block_description_print(struct stitch_block_description *block)
{
    printf("IsOpenPath:                     %d\n", block->IsOpenPath);
    printf("UseOutline:                     %d\n", block->UseOutline);
    printf("OutlineStitchType:              ");
    switch(block->OutlineStitchType)
    {
    case 0:
        printf("Zigzag Stitch\n");
        break;
    case 1:
        printf("Running Stitch\n");
        break;
    case 2:
        printf("Triple Stitch\n");
        break;
    case 3:
        printf("Motif Stitch\n");
        break;
    case 4:
        printf("Stem Stitch\n");
        break;
    case 5:
        printf("Candlewicking Stitch\n");
        break;
    case 6:
        printf("E/V Stitch\n");
        break;
    }
    printf("Outline Color Index:            %d\n", block->outline_color_index);
    printf("ZigzagWidth:                    %f\n", block->ZigzagWidth / 10.0f);
    printf("ZigzagDensity:                  %f\n", block->ZigzagDensity / 10.0f);
    printf("OutlineRunPitch:                %d\n", block->OutlineRunPitch);
    printf("RunStitchRunTimes:              %d\n", block->RunStitchRunTimes);

    printf("Triple stitch run pitch:        %d\n", block->triple_stitch_run_pitch);

    printf("OutlineUseHalfStitch:           %d\n", block->OutlineUseHalfStitch);
    printf("Use Outline Under Sewing:       %d\n", block->UseOutlineUnderSewing);
    printf("UseSharpCorners:                %d\n", block->UseSharpCorners);
    motif_stitch_print(block->MotifLine);
    
    printf("EStitchOrVStitch:               %s\n", (block->EStitchOrVStitch == 0) ? "E-Stitch" : "V-Stitch");
    printf("EvStitchTallWidth:              %d\n", block->EvStitchTallWidth);
    printf("EvStitchHeight:                 %d\n", block->EvStitchHeight);
    printf("EvStitchPointWidth:             %d\n", block->EvStitchPointWidth);
    printf("EvStitchRunTimes:               %d\n", block->EvStitchRunTimes);
    printf("EvStitchStrokeTimes:            %d\n", block->EvStitchStrokeTimes);
    printf("EvStitchArrange:                %d\n", block->EvStitchArrange);

    printf("UseFill:                        %d\n", block->UseFill);
    printf("FillType:                       ");
    switch(block->FillType)
    {
    case 0:
        printf("Zigzag\n");
        break;
    case 1: 
        printf("Fill Stitch\n");
        break;
    case 2:
        printf("Run Stitch\n");
        break;
    case 3:
        printf("Motif\n");
        break;
    }
    
    printf("RegionDensity:                  %d\n", block->RegionDensity);
    printf("UseGradation:                   %d\n", block->UseGradation);

    short_array_print(block->GradationValues);
    
    printf("UseAdditionalColorInGradation:  %d\n", block->UseAdditionalColorInGradation); 
    printf("Gradation Second Color:         %d\n", block->gradation_second_color);
    printf("IsStitchDirectionVariable:      %d\n", block->IsStitchDirectionVariable);
    printf("StitchDirection:                %d\n", block->StitchDirection);
    printf("Fill Color Index:               %d\n", block->fill_color_index);
    printf("BaseSewingStepPitch:            %d\n", block->BaseSewingStepPitch / 10.0f);
    printf("BaseSewingFrequency:            %d\n", block->BaseSewingFrequency);
    printf("BaseSewingStitchType:           %d\n", block->BaseSewingStitchType);
    printf("FillHalfStitch:                 %d\n", block->FillHalfStitch);
    printf("UseFillAreaUnderSewing:         %d\n", block->useFillAreaUnderSewing);
    printf("FillAreaUnderSewingType:        %d\n", block->FillAreaUnderSewingType);
    printf("Running Stitch Path:            %d\n", block->RunningStitchPath);
    
    printf("Programmable Fill PatternIndex: %d\n", block->ProgrammableFillPatternIndex);
    printf("Programmable Fill Width:        %d\n", block->ProgrammableFillWidth);
    printf("Programmable Fill Height:       %d\n", block->ProgrammableFillHeight);
    printf("Programmable Fill RowOrColumn:  %d\n", block->ProgrammableFillRowOrColumn);
    printf("Programmable Fill RowOffset:    %d\n", block->ProgrammableFillRowOffset);
    printf("Programmable Fill ColumnOffset: %d\n", block->ProgrammableFillColumnOffset);
    printf("Programmable Fill Direction:    %d\n", block->ProgrammableFillDirection);

    printf("UseBaseSewing:                  %d\n", block->UseBaseSewing);
    printf("Pull Compensation:              %d\n", block->PullCompensation);
    // Motif section
    
    printf("Use Motif Pattern1:             %d\n", block->UseMotifPattern1); // default: false
    
    motif_print(block->MotifFillPattern1);
    
    motif_print(block->MotifFillPattern2);
    
    printf("MotifRowOffset:                 %d\n", block->MotifRowOffset);
    printf("MotifStitchDirection:           %d\n", block->MotifStitchDirection);
    printf("MotifRunPitch:                  %d\n", block->MotifRunPitch);
    
    printf("\n");
    printf("pipingStitchDirection:          %d\n", block->pipingStitchDirection);
    printf("pipingStitchDensity:            %d\n", block->pipingStitchDensity);
    printf("pipingStitchRunPitch:           %d\n", block->pipingStitchRunPitch);
    printf("pipingStitchFrequency:          %d\n", block->pipingStitchFrequency);
    printf("\n");
    
    // CrossStitch section
    printf("CrossStitchSizeMeasure:         %d\n", block->CrossStitchSizeMeasure);
    printf("CrossStitchSizeInMM:            %d\n", block->CrossStitchSizeInMM);
    printf("CrossStitchTimes:               %d\n", block->CrossStitchTimes);
    printf("\n");
    printf("RadialDensity:                  %d\n", block->RadialDensity);
    printf("RadialRunPitch:                 %d\n", block->RadialRunPitch);
    printf("RadialCenterX:                  %d\n", block->RadialCenterX);
    printf("RadialCenterY:                  %d\n", block->RadialCenterY);
    printf("\n");
    printf("ConcentricCircleDensity:        %d\n", block->ConcentricCircleDensity);
    printf("ConcentricCircleRunPitch:       %d\n", block->ConcentricCircleRunPitch);
    printf("ConcentricCircleCenterX:        %d\n", block->ConcentricCircleCenterX);
    printf("ConcentricCircleCenterY:        %d\n", block->ConcentricCircleCenterY);
    printf("\n");
    printf("Spiral Density:                 %d\n", block->SpiralDensity);
    printf("Spiral Run Pitch                %d\n", block->SpiralRunPitch);
    
    printf("Stipling Run Pitch:             %d\n", block->StipplingRunPitch);
    printf("Stipling Spacing:               %d\n", block->StipplingSpacing);

    printf("OutlineEntryv1:                 %d\n", block->OutlineEntryv1);
    printf("%f\n", block->OutlineEntry);
    
    printf("OutlineExitv1:                  %d\n", block->OutlineExitv1);
    printf("%f\n", block->OutlineExit);
    
    printf("RegionEntryv1:                  %d\n", block->RegionEntryv1);
    printf("%f\n", block->RegionEntry);
    
    printf("RegionExitv1:                   %d\n", block->RegionExitv1);
    printf("%f\n", block->RegionExit);
}


void stitch_block_description_free(struct stitch_block_description *block)
{
    block_geometry_free(block->geometry);
    motif_stitch_free(block->MotifLine);
    short_array_free(block->GradationValues);
    motif_free(block->MotifFillPattern1);
    motif_free(block->MotifFillPattern2);
    free(block);
}