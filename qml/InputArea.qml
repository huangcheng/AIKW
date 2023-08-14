import QtQuick

Rectangle {
    readonly property string placeholderColor: '#7F829F'
    readonly property string textColor: '#1D2126'

    property alias text: edit.text
    property alias readOnly: edit.readOnly
    property string placeholder: ''

    id: root
    color: '#F2F4F5'
    radius: 4

    Flickable {
         id: flick

         anchors.fill: parent

         leftMargin: 10
         rightMargin: 10
         topMargin: 10
         bottomMargin: 10

         contentWidth: edit.contentWidth
         contentHeight: edit.contentHeight
         clip: true

         function ensureVisible(r)
         {
             if (contentX >= r.x)
                 contentX = r.x;
             else if (contentX+width <= r.x+r.width)
                 contentX = r.x+r.width-width;
             if (contentY >= r.y)
                 contentY = r.y;
             else if (contentY+height <= r.y+r.height)
                 contentY = r.y+r.height-height;
         }

         TextEdit {
             id: edit
             width: flick.width
             focus: true
             wrapMode: TextEdit.Wrap
             onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)

             Text {
                 visible: !edit.text
                 text: placeholder
                 height: parent.height
                 color: placeholderColor

                 anchors.left: parent.left
                 anchors.verticalCenter: parent.verticalCenter
             }
         }
     }

}
