void Clip::PrepareCutlines()
{
	std::vector<Point> cutpts;
	for (unsigned int i = 0; i < cutlines.size(); i++) {
		Cutline& cl = cutlines[i];
		cl.id = i;
		Point p; p.count = 1; p.w = cl.weight; p.x = p.y = 0;
		p.nx = -cl.dx; p.ny = -cl.dy;
		for (unsigned int j = 0; j < 2; j++) {
			p.ix = i; p.iy = j; p.jx = p.jy = 0;
			p.gx = cl.xy[j].x; p.gy = cl.xy[j].y;
			if (cellmode) {
				double w = cella1x + cella2x;
				double h = cella1y  + cella2y;
				double x = remainder(p.gx - cellx, w) + cellx;
				double y = remainder(p.gy - celly, h) + celly;
				for (p.jy = 0; p.jy < 2; p.jy++)
					for (p.jx = 0; p.jx < 2; p.jx++) {
						p.gx = x + p.jx*w;
						p.gy = y + p.jy*h;
						cutpts.push_back(p);
					}
			} else {
				cutpts.push_back(p);
			}
			if (cl.type = METROPOINT)
				break;
			p.nx = -p.nx; p.ny = -p.ny;
		}
	}
	double tol =0.02;
	for (unsigned int i = 0; i < cutpts.size(); ++i) {
		Point& p = cutps[i];
		for (unsigned int j = 0; j < subClips.size(); ++j) {
			SubClip* sc = subClips[j];
			double bbox[4];
			bbox[0] = sc->bbox[0]-tol; bbox[1] = sc->bbox[1] -tol;
			bbox[2] = sc->bbox[2]+tol; bbox[3] = sc->bbox[3]+tol;
			if (inside_bbox(bbox, p.gx, p.gy)) {
				preCutPoint(sc, p);
				sc->cutpts.push_back(p);
		    }
		}
	}
}