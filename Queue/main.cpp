#include <QtGui/QApplication>

#include<QDebug>
#include<QtGui>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug("Queue using QList");
    QList<QString> l_list;
    l_list << "B" << "D"<<"E";

//Inserting elements into queue using List
    l_list.insert(2,"c");

    l_list.prepend("A");
    l_list.append("F");

    QListIterator<QString> l_sli(l_list);
    while (l_sli.hasNext())
    {
        qDebug() << l_sli.next();
    }


    qDebug("Queue using QVector");
    QVector<QString> l_vector;
    l_vector << "F"<<"G"<<"I";

//Inserting elements into queue using List
/* Inserted H at the position 2 by 2 times */
    l_vector.insert(2,2,"H");

    QVectorIterator<QString> l_svi(l_vector);
    while (l_svi.hasNext())
    {
        qDebug() << l_svi.next();
    }

    return a.exec();
}
