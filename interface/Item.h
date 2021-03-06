/*
****************************************************************
* Copyright (c) 2004-2010,	Jan-Rixt Van Hoye				   *
* All rights reserved.										   *
* Distributed under the terms of the MIT License.              *
****************************************************************
*/
// File defenition
#ifndef ITEM_H
#define ITEM_H

//		Includes
#include <interface/ListView.h>
#include <interface/Region.h>
#include <stdlib.h>
//
//		Local Includes
#include "intf_global.h"
#include "core_global.h"
#include "ItemData.h"

 //		define classes
//
class BeCam_Item : public BListItem 
{
	public:
						BeCam_Item(ItemData *data);
						BeCam_Item();
						~BeCam_Item();
		virtual void 	DrawItem(BView *owner, BRect frame, bool complete = false);
		virtual void 	Update(BView *owner, const BFont *font);
		const char* 	GetName();
		const char*		GetDate();
		uint32			GetHandle();
		uint32			GetSize();
		BBitmap*		GetThumbBitmap();
		char*			GetItemPath();
		uint32			GetStatus();
		uint32			GetOrientation();
		float			Height() const;
		float			Width() const;
		float			ThumbHeight() const;
		float			ThumbWidth() const;
		float			DetailsHeight() const;
		virtual bool	IsClickableFrame (BPoint point) const;
		void 			RotateThumb(uint32 angle);
		
	private:
		ItemData		*itemdata;
		BRegion			fRegion;
		float			fFontHeight;
		float			fThumbDetailsGap;
};

#endif


