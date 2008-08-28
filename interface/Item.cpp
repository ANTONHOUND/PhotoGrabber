�
�;   �2         ��       ���H  ����H     �2                                                                                                                                                                                    RTSC     lock                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        lete)
		{	
			itemView->SetHighColor(owner->ViewColor());
			itemView->SetLowColor(owner->ViewColor());
			itemView->FillRect (itemView->Bounds());
			itemView->StrokeRect (itemView->Bounds());
		}
		
		//if (IsEnabled())
		//	itemView->SetHighColor(color_enabled);
		//else
		//	itemView->SetHighColor(color_disabled);
		
		if(thumbRect.right < thumbRect.bottom)
			thumbRect.right = thumbRect.bottom;
		thumbRect.left = xItemBitmapPos - floor(thumbWidth/2);
		thumbRect.right = xItemBitmapPos + ceil(thumbWidth/2);
		thumbRect.top = yItemBitmapPos - floor(thumbHeight/2);
		thumbRect.bottom = yItemBitmapPos + floor(thumbHeight/2);
		//	Draw the thumbnail
		itemView->DrawBitmapAsync(thumbnail,thumbRect);
		thumbRect.right += 1; // bug Haiku
		if(!IsSelected())
		{
			itemView->SetHighColor (color_picture);
			itemView->SetLowColor (color_picture);
		}
		else
		{
			itemView->SetPenSize(3);
			itemView->SetHighColor (color_selected);
			itemView->SetLowColor (color_selected);
		}
		itemView->StrokeRect (thumbRect);
		itemView->Sync();
		itemBitmap->Unlock();
		
		owner->DrawBitmapAsync(itemBitmap,frame);
		owner->Sync();
		owner->SetDrawingMode( B_OP_COPY );
	}
	else
	{
		// Move the pen to draw
		owner->MovePenTo(frame.left,frame.top);
		
		thumbRect.left=0;
		thumbRect.right=159;
		thumbRect.top=0;
		thumbRect.bottom=119;
		//	Draw a string	
		owner->DrawString("No thumbnail");
	}
	delete(itemBitmap);
	fRegion.Include(thumbRect);
}

//
//	Item::Update

void BeCam_Item::Update(BView *owner, const BFont *font)
{
	BRect	rect;

	if(GetThumbBitmap())
	{
		rect=GetThumbBitmap()->Bounds();
		SetHeight((rect.bottom)+8);
	}
	else
	{
		SetHeight((119)+8);
	}
}
//
//	Item::Get Name
const char* BeCam_Item::GetName()
{
	return itemdata->ItemName.String();
}
//
//	Item::Get Thumb Bitmap
BBitmap* BeCam_Item::GetThumbBitmap()
{
	return itemdata->ItemThumbBitmap;
}
//
//	Item::Get Item
char* BeCam_Item::GetItemPath()
{
	return itemdata->ItemPath;
}
//
//	Item::Get Date
const char* BeCam_Item::GetDate()
{
	return itemdata->ItemDate.String();
}
//
//	Item::Get Name
uint32 BeCam_Item::GetHandle()
{
	return itemdata->ItemHandle;
}
//
//	Item::Get Size
uint32 BeCam_Item::GetSize()
{
	return itemdata->ItemSize;
}
//
//	Item::Get Orientation
uint32 BeCam_Item::GetOrientation()
{
	return itemdata->ItemOrientation;
}
//
//	Item::Height
float BeCam_Item::Height() const
{
	return fHeight;
}
//
//	Item::Width
float BeCam_Item::Width() const
{
	return fWidth;
}
//
//	Item:: Is Clickable Frame
bool BeCam_Item::IsClickableFrame (BPoint point) const
{
	for (int32 i = 0; i < fRegion.CountRects(); i++)
		if (fRegion.RectAt(i).Contains (point))
			return true;
	
	return false;
}
