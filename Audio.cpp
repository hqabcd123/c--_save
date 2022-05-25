#include <iostream>
#include "mem.h"
using namespace std;
#define PATH "./Audio/Audio.wav"
#define OUTPATH "./Audio/outAudio.wav"

int getFileSize(FILE *inFile);

typedef struct wav_header{
    uint8_t RIFF[4];
    uint32_t ChinkSize;
    uint8_t WAV[4];
    uint8_t fmt[4];
    uint32_t SubchunkSize;
    uint16_t AudioFormat;
    uint16_t NumOfChan;
    uint32_t SimplesPerSec;
    uint32_t bytesPerSec;
    uint16_t blockAlign;
    uint16_t bitsPerSimple;
    uint8_t Subchunk2ID[4];
    uint32_t Subchunk2Size;
} wav_header;

int main(){
    cout << "\n\n\n\n"
         << endl;
    wav_header wavHeader;
    FILE *file = fopen(PATH, "rb");
    int headerSize = sizeof(wavHeader);
    if (file == NULL){
        cout << "Path is not work" << endl;
        return 1;
    }
    size_t bytesRead = fread(&wavHeader, headerSize, 1, file);
    cout << "Header Read " << bytesRead << " bytes" << endl;
    cout << "header size is " << headerSize << endl;

    if (bytesRead > 0){
        uint16_t bytesPerSample = wavHeader.bitsPerSimple/8;//How many bytes per sample
        uint32_t numSamples = wavHeader.ChinkSize / bytesPerSample;//How many sample they are
        cout << "bytesPerSample and numSamples is: " << bytesPerSample << ", " << numSamples << endl;
        //static const uint16_t BUFFER_SIZE = 4096;
        uint64_t length = getFileSize(file);
        uint16_t *value = new uint16_t[length/2];
        uint64_t count = 0;
        while ((bytesRead = fread(value, sizeof value[0], length/2, file)) > 0){
            count++;
        }
        cout << "run " << count << " times" << endl;
        FILE *fout = fopen(OUTPATH, "wb");
        //fwrite(value, sizeof value[0], length/2, fout);
        /*****************************************************************/
        uint16_t *temp = new uint16_t[length/2];
        //fwrite(&wavHeader, headerSize, 1, fout);
        for (int i = 0; i < headerSize; i++)
        {
            temp[i] = value[i];
        }
        for (int i = headerSize; i < length/2; i++)
        {
            temp[i] = value[i];
        }
        fwrite(temp, sizeof temp[0], (length/2), fout);
        /*****************************************************************/
        fclose(file);
        fclose(fout);

        cout << "flie is " << length << "bytes" << endl;
        cout << "RIFF header : " << wavHeader.RIFF[0] << wavHeader.RIFF[1] 
        << wavHeader.RIFF[2] << wavHeader.RIFF[3] << endl;
        cout << "WAV header : " << wavHeader.WAV[0] << wavHeader.WAV[1] 
        << wavHeader.WAV[2] << wavHeader.WAV[3] << endl;
        cout << "FMT: " << wavHeader.fmt[0] << wavHeader.fmt[1] << wavHeader.fmt[2] << wavHeader.fmt[3] << endl;
        cout << "data size: " << wavHeader.ChinkSize << endl;
        cout << "Sampling Rate: " << wavHeader.SimplesPerSec << endl;
        cout << "Number of bit used: " << wavHeader.bitsPerSimple << endl;
        cout << "Number of channels: " << wavHeader.NumOfChan << endl;
        cout << "Number of bytes per second: " << wavHeader.bytesPerSec << endl;
        cout << "Data length: " << wavHeader.Subchunk2Size << endl;
        cout << "Audio length: " << wavHeader.AudioFormat << endl;
        cout << "Block align: " << wavHeader.blockAlign << endl;
        cout << "Data string: " << wavHeader.Subchunk2ID[0] << wavHeader.Subchunk2ID[1]
         << wavHeader.Subchunk2ID[2] << wavHeader.Subchunk2ID[3] << endl;
        // short *Data = new short[wavHeader.Subchunk2Size / (wavHeader.bitsPerSimple / 8)];
        // fread(Data, wavHeader.bitsPerSimple / 8, wavHeader.Subchunk2Size / (wavHeader.bitsPerSimple / 8), file);
    }

    return 0;
}

int getFileSize(FILE* inFile){
    int fileSize = 0;
    fseek(inFile, 0, SEEK_END);

    fileSize = ftell(inFile);

    fseek(inFile, 0, SEEK_SET);
    return fileSize;
}