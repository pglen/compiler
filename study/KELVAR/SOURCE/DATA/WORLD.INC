
macro image name,file,x,y,width,height,hook_x,hook_y
 {
   local image
   image:
   name = ($-images)/.size
     .status db 1
     .file dd file
     .x dd x
     .y dd y
     .picture dd ?
     .source dd ?
     .pitch dd ?
     .width dd width
     .height dd height
     .hook_x dd hook_x+0
     .hook_y dd hook_y+0
     .size = $-.status
 }

macro plane image,x,y
 {
   local plane
   plane:
     .image_id dd image
     .x dd x
     .y dd y
     .size = $-.image_id
 }

macro object id,image,frame,x,y,layer
 {
   local object
   object:
     .id db id
     .refresh db 0
     .layer db layer
     .image_id dd image
     .frame_id dw frame
     .x dd x
     .y dd y
     .image dd ?
     .frame dd ?
     .previous_x dd ?
     .previous_y dd ?
     .previous_image dd ?
     .previous_frame dd ?
     .size = $-.id
 }

macro zone id,x,y,width,height,data
 {
   local zone
   zone:
     .id db id
     .x dd x
     .y dd y
     .width dd width
     .height dd height
     .data dd data+0
     .size = $-.id
 }

macro event id,data
 {
   local event
   event:
     .id db id
     .data dd data
     .size = $-.id
 }

macro text image_id,x,y,file
 {
   local text
   text:
     .image_id dd image_id
     .x dd x
     .y dd y
     .file dd file
     .size = $-.image_id
 }
