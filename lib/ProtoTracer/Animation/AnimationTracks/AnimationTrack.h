#pragma once

#include "..\KeyFrameTrack.h"

template<size_t maxParameters, size_t maxKeyFrames>
class AnimationTrack{
protected:
    KeyFrameTrack<maxParameters, maxKeyFrames> track;

private:
    virtual void AddKeyFrames();

public:
    AnimationTrack() : track(KeyFrameTrack<maxParameters, maxKeyFrames>(0.0f, 1.0f, KeyFrameInterpolation::Cosine)){}
    
    AnimationTrack(float min, float max, KeyFrameInterpolation::InterpolationMethod interpMethod) : track(KeyFrameTrack<maxParameters, maxKeyFrames>(min, max, interpMethod)){}

    void Play(){
        track.Play();
    }

    void Pause(){
        track.Pause();
    }

    void RestartTime(){
        track.SetCurrentTime(0.0f);
    }

    void PrintTime(){
        Serial.println(track.GetCurrentTime());
    }

    void Reset(){
        track.Reset();
    }

    float GetParameterValue(){
        return track.GetParameterValue();
    }

    float Update(){
        return track.Update();
    }

    void AddParameter(float* parameter){
        track.AddParameter(parameter);
    }

};