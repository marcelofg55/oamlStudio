//-----------------------------------------------------------------------------
// Copyright (c) 2015-2016 Marcelo Fernandez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#ifndef __WAVEFORMDISPLAY_H__
#define __WAVEFORMDISPLAY_H__

class RenderTimer : public wxTimer {
	wxWindow* pane;
public:
	RenderTimer(wxWindow* pane);

	void Notify();
};

class WaveformDisplay : public wxPanel {
private:
	RenderTimer* timer;

	std::string path;
	std::string filename;
	std::string audioName;
	audioFile *handle;
	ByteBuffer buffer;

	int peakl;
	int peakr;
	int count;

	std::vector<int> peaksL;
	std::vector<int> peaksR;

	int bytesPerSec;
	int samplesPerPixel;

public:
	WaveformDisplay(wxFrame* parent);
	~WaveformDisplay();

	int read32();
	void SetSource(std::string _filename, std::string _audioName, bool sfxMode);

	void OnPaint(wxPaintEvent& evt);
	void OnLeftUp(wxMouseEvent& evt);
	void OnRightUp(wxMouseEvent& evt);
	void OnMenuEvent(wxCommandEvent& evt);
	void OnEraseBackground(wxEraseEvent& evt);

	std::string GetFilename() { return filename; }
	std::string GetAudioName() { return audioName; }
	void SetAudioName(std::string name) { audioName = name; }

	void SetStatusText(wxString status);
};

#endif
